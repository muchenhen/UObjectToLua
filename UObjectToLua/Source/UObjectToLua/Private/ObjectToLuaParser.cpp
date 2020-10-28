#include "ObjectToLuaParser.h"
#include "Math/UnrealMathUtility.h"

DEFINE_LOG_CATEGORY(ObjectToLua);

//加载UClass模板
template<typename T>
UClass* loadClassT(const char* cls) {
	FString path(UTF8_TO_TCHAR(cls));
	int32 index;
	if (!path.FindChar(TCHAR('\''), index)) {
		// load blueprint widget from cpp, need add '_C' tail
		path = FString::Format(TEXT("Blueprint'{0}_C'"), { path });
	}
	else
		// auto add _C suffix
	{
		// remove last '
		path = path.Left(path.Len() - 1);
		path += TEXT("_C'");
	}

	UClass* classObj = LoadClass<T>(NULL, *path);
	return classObj;
}

//获取UProperty的模板
template <typename ValueType>
ValueType GetPropertyValue(UProperty* Property, void* Object)
{
	ValueType* SourceAddr = Property->ContainerPtrToValuePtr<ValueType>(Object);
	if (SourceAddr)
	{
		return *SourceAddr;
	}
	return *SourceAddr;
}

//设置UProperty的模板
template <typename ValueType>
bool SetPropertyValue(UProperty* Property, void* Object, ValueType Value)
{
	// Get the property addresses for the object
	ValueType* SourceAddr = Property->ContainerPtrToValuePtr<ValueType>(Object);

	if (SourceAddr == NULL)
	{
		return false;
	}

	// Set the value on the destination object.
	*SourceAddr = Value;
	return true;
}

FString UObjectToLuaParser::ToCompressFloatStr(float F, bool DefaultAsEmpty)
{
	float Res = (int)(F * 100.0f + 0.5f) / 100.0f;
	if (DefaultAsEmpty && FMath::IsNearlyZero(Res))
	{
		return FString();
	}
	else
	{
		return FString::SanitizeFloat(Res);
	}
}

FString UObjectToLuaParser::ToObjectStr(UObject* Object, bool DefaultAsEmpty)
{
	FString TotalALLNames;
	int ElNum = 0;
	//遍历所有被UProperty标记的成员
	for (TFieldIterator<UProperty> PropertyIterator(Object->GetClass()); PropertyIterator; ++PropertyIterator)
	{
		UProperty* Property = *PropertyIterator;
		FString PropertyName = Property->GetName();

		//判断UProperty类型
		FString KVStr = CheckUproperType(Property, Object, DefaultAsEmpty);

		if (!KVStr.IsEmpty())
		{
			if (ElNum > 0)
			{
				TotalALLNames.Append(",");
			}
			TotalALLNames.Append(KVStr);
			ElNum++;
		}
	}

	if (DefaultAsEmpty && TotalALLNames.IsEmpty())
	{
		return FString();
	}
	else
	{
		return FString::Printf(TEXT("{%s}"), *TotalALLNames);
	}
}

FString UObjectToLuaParser::ToStructStr(UScriptStruct* Struct, void* Object, bool DefaultAsEmpty)
{
	FString TotalALLNames;
	int ElNum = 0;
	UField* Field = Struct->Children;
	while (Field)
	{
		// Get Blueprint name
		if (UProperty * Property = Cast<UProperty>(Field))
		{
			FString PropertyName = Property->GetName();

			//判断UProperty类型
			FString KVStr = CheckUproperType(Property, Object, DefaultAsEmpty);

			if (!KVStr.IsEmpty())
			{
				if (ElNum > 0)
				{
					TotalALLNames.Append(",");
				}
				TotalALLNames.Append(KVStr);
				ElNum++;
			}
		}

		// Go to next member
		Field = Field->Next;
	}

	if (DefaultAsEmpty && TotalALLNames.IsEmpty())
	{
		return FString();
	}
	else
	{
		return FString::Printf(TEXT("{%s}"), *TotalALLNames);
	}
}

FString UObjectToLuaParser::CheckUproperType(UProperty* Property, void* Object, bool DefaultAsEmpty)
{
	const FString& PropertyStr = GetPropertyValueLuaStr(Property, Object, DefaultAsEmpty);
	if (PropertyStr.IsEmpty() && DefaultAsEmpty)
	{
		return FString();
	}
	else
	{
		return FString::Printf(TEXT("%s=%s"), *Property->GetName(), *PropertyStr);
	}
}

FString UObjectToLuaParser::GetPropertyValueLuaStr(UProperty* Property, void* Object, bool DefaultAsEmpty)
{
	if (Cast<UBoolProperty>(Property))
	{
		bool tempBool = GetPropertyValue<bool>(Property, Object);
		if (DefaultAsEmpty && !tempBool)
		{
			return FString();
		}
		else
		{
			return tempBool ? FString("true") : FString("false");
		}
	}
	else if (Cast<UIntProperty>(Property))
	{
		int32 tempInt = GetPropertyValue<int>(Property, Object);

		if (DefaultAsEmpty && tempInt == 0)
		{
			return FString();
		}
		else
		{
			return FString::FromInt(tempInt);
		}
	}
	else if (Cast<UFloatProperty>(Property))
	{
		float tempFloat = GetPropertyValue<float>(Property, Object);
		return ToCompressFloatStr(tempFloat, DefaultAsEmpty);
	}
	else if (Cast<UStrProperty>(Property))
	{
		FString tempString = GetPropertyValue<FString>(Property, Object);
		if (DefaultAsEmpty && tempString.IsEmpty())
		{
			return FString();
		}
		else
		{
			return FString::Printf(TEXT("'%s'"), *tempString);
		}
	}
	else if (UArrayProperty * ArrayProperty = Cast<UArrayProperty>(Property))
	{
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayProperty->ContainerPtrToValuePtr<void>(Object));
		int ArrNum = 0;
		FString ArrayAllNames = "{";
		int NilNum = 0;
		for (int i = 0; i < ArrayHelper.Num(); i++)
		{
			void* ValuePtr = ArrayHelper.GetRawPtr(i);
			FString InnerStr = GetPropertyValueLuaStr(ArrayProperty->Inner, ValuePtr, DefaultAsEmpty);
			if (DefaultAsEmpty && InnerStr.IsEmpty())
			{
				NilNum++;
			}
			else
			{
				if (ArrNum > 0)
				{
					ArrayAllNames.Append(",");
				}

				ArrNum += NilNum;
				for (int j = 0; j < NilNum; j++)
				{
					ArrayAllNames.Append("nil,");
				}
				NilNum = 0;
				
				ArrayAllNames.Append(InnerStr.IsEmpty() ? TEXT("nil") : *InnerStr);
				ArrNum++;
			}
		}
		if (DefaultAsEmpty && ArrNum == 0)
		{
			return FString();
		}
		else
		{
			ArrayAllNames.Append("}");
			return ArrayAllNames;
		}
	}
	else if (UMapProperty * MapProperty = Cast<UMapProperty>(Property))
	{
		FScriptMapHelper MapHelper(MapProperty, MapProperty->ContainerPtrToValuePtr<void>(Object));
		FString KeyName;
		FString ValueName;
		int MapNum = 0;
		FString MapStr = "{";
		for (int i = 0; i < MapHelper.Num(); i++)
		{
			KeyName = GetPropertyValueLuaStr(MapProperty->KeyProp, MapHelper.GetKeyPtr(i), DefaultAsEmpty);
			if (KeyName.IsEmpty())
			{
				continue;
			}
			ValueName = GetPropertyValueLuaStr(MapProperty->ValueProp, MapHelper.GetValuePtr(i), DefaultAsEmpty);
			if (ValueName.IsEmpty())
			{
				continue;
			}
			if (MapNum > 0)
			{
				MapStr.Append(",");
			}
			MapStr.Append(FString::Printf(TEXT("[%s]=%s"), *KeyName, *ValueName));
			MapNum++;
		}
		if (DefaultAsEmpty && MapNum == 0)
		{
			return FString();
		}
		else
		{
			MapStr.Append("}");
			return MapStr;
		}
	}
	else if (UStructProperty * StructProperty = Cast<UStructProperty>(Property))
	{
		if (StructProperty->Struct == TBaseStructure<FVector>::Get())
		{
			FVector vec = GetPropertyValue<FVector>(Property, Object);
			if (DefaultAsEmpty && vec == FVector::ZeroVector)
			{
				return FString();
			}
			else
			{
				FString VectorAll = "{";
				VectorAll.Append(FString::Printf(TEXT("X=%s,"), *ToCompressFloatStr(vec.X)));
				VectorAll.Append(FString::Printf(TEXT("Y=%s,"), *ToCompressFloatStr(vec.Y)));
				VectorAll.Append(FString::Printf(TEXT("Z=%s}"), *ToCompressFloatStr(vec.Z)));
				return VectorAll;
			}
		}
		else if (StructProperty->Struct == TBaseStructure<FRotator>::Get())
		{
			FRotator rot = GetPropertyValue<FRotator>(Property, Object);
			if (DefaultAsEmpty && rot == FRotator::ZeroRotator)
			{
				return FString();
			}
			else
			{
				FString RotatorAll = "{";
				RotatorAll.Append(FString::Printf(TEXT("Pitch=%s,"), *ToCompressFloatStr(rot.Pitch)));
				RotatorAll.Append(FString::Printf(TEXT("Yaw=%s,"), *ToCompressFloatStr(rot.Yaw)));
				RotatorAll.Append(FString::Printf(TEXT("Roll=%s}"), *ToCompressFloatStr(rot.Roll)));
				return RotatorAll;
			}
		}
		else if (StructProperty->Struct == TBaseStructure<FSoftObjectPath>::Get())
		{
			FSoftObjectPath SoftObjectPath = GetPropertyValue<FSoftObjectPath>(Property, Object);
			if (DefaultAsEmpty && !SoftObjectPath.IsValid())
			{
				return FString();
			}
			else
			{
				return FString::Printf(TEXT("'%s'"), *SoftObjectPath.GetAssetPathString());
			}
		}
		else if (StructProperty->Struct == TBaseStructure<FSoftClassPath>::Get())
		{
			FSoftClassPath SoftClassPath = GetPropertyValue<FSoftClassPath>(Property, Object);
			if (DefaultAsEmpty && !SoftClassPath.IsValid())
			{
				return FString();
			}
			else
			{
				return FString::Printf(TEXT("'%s'"), *SoftClassPath.GetAssetPathString());
			}
		}
		else if(StructProperty->Struct->IsNative())
		{
			return ToStructStr(StructProperty->Struct, Object, DefaultAsEmpty);
		}
		else
		{
			UE_LOG(ObjectToLua, Warning, TEXT("Unrecognized Struct Property: %s"), *Property->GetName());
			if (DefaultAsEmpty)
			{
				return FString();
			}
			else
			{
				return FString("nil");
			}
		}
	}
	else if (UObjectProperty * ObjectProperty = Cast<UObjectProperty>(Property))
	{
		UObject* tempUObject = GetPropertyValue<UObject*>(ObjectProperty, Object);

		if (!tempUObject)
		{
			if (DefaultAsEmpty)
			{
				return FString();
			}
			else
			{
				return FString("{}");
			}
		}
		else
		{
			return ToObjectStr(tempUObject, DefaultAsEmpty);
		}
	}
	else if (USetProperty * SetProperty = Cast<USetProperty>(Property))
	{
		FScriptSetHelper SetHelper(SetProperty, SetProperty->ContainerPtrToValuePtr<void>(Object));
		int SetNum = 0;
		FString SetAllNames = "{";
		for (int i = 0; i < SetHelper.Num(); i++)
		{
			void* ValuePtr = SetHelper.GetElementPtr(i);
			const FString& Key = GetPropertyValueLuaStr(SetProperty->ElementProp, ValuePtr, DefaultAsEmpty);
			if (Key.IsEmpty())
			{}
			else
			{
				if (SetNum > 0)
				{
					SetAllNames.Append(",");
				}
				SetNum++;
				SetAllNames.Append(FString::Printf(TEXT("[%s]=true"), *Key));
			}
		}
		
		if (DefaultAsEmpty && SetNum == 0)
		{
			return FString();
		}
		else
		{
			SetAllNames.Append("}");
			return SetAllNames;
		}
	}
	else if (UEnumProperty * EnumProperty = Cast<UEnumProperty>(Property))
	{
		uint8 tempint8 = GetPropertyValue<uint8>(Property, Object);
		if (DefaultAsEmpty && tempint8 == 0)
		{
			return FString();
		}
		else
		{
			return FString::FromInt(tempint8);
		}
	}

	UE_LOG(ObjectToLua, Warning, TEXT("Unrecognized Property: %s"), *Property->GetName());
	if (DefaultAsEmpty)
	{
		return FString();
	}
	else
	{
		return FString("nil");
	}
}

void UObjectToLuaParser::CheckSetType(UProperty* Property, void* Object, FString value)
{
	if (Cast<UBoolProperty>(Property))
	{
		bool tempBool = value.ToBool();
		SetPropertyValue(Property, Object, tempBool);
	}
	else if (Cast<UIntProperty>(Property))
	{
		int32 tempInt = FCString::Atoi(*value);
		SetPropertyValue(Property, Object, tempInt);
	}
	else if (Cast<UFloatProperty>(Property))
	{
		float tempFloat = FCString::Atof(*value);
		SetPropertyValue(Property, Object, tempFloat);
	}
	else if (Cast<UStrProperty>(Property))
	{
		value.RemoveAt(0, 1);
		value.RemoveAt(value.Len() - 1, 1);
		SetPropertyValue(Property, Object, value);
	}
	else if (UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Property))
	{
		value.RemoveAt(0, 1);
		value.RemoveAt(value.Len() - 1, 1);

		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayProperty->ContainerPtrToValuePtr<void>(Object));
		
		int numOfArray = 0;//设置的目标数组的元素个数
		FString temArrayVal;
		
		int flags = 0;
		for (int i = 0; i < value.Len(); i++)
		{
			if (value[i] == '{')
			{
				flags++;
			}
			if (value[i] == '}')
			{
				flags--;
			}
			if (value[i] == ',' && flags == 0)
			{
				numOfArray++;
			}
		}
		flags = 0;
		//目标数组元素个数大于0 需要重新设置数组大小
		if (numOfArray >= 0)
		{
			ArrayHelper.Resize(numOfArray);
		}
		int count = 0;//
		//依次设置数组的每个元素
		for (int i = 0; i < ArrayHelper.Num(); i++)
		{
			//处理value，取出对应索引的元素值
			for (; count < value.Len(); count++)
			{
				if (value[count] == '{')
				{
					flags++;
				}
				if (value[count] == '}')
				{
					flags--;
				}
				if (value[count] != '{' && value[count] != '}')
				{
					//遇到逗号跳过
					if (value[count] == ',' && flags == 0)
					{
						count++;
						break;
					}
					else if (value[count] == ',' && flags != 0)
					{
						temArrayVal += value[count];
						continue;
					}
					temArrayVal += value[count];
				}
			}
			if (UObjectProperty* tempObjectProperty = Cast<UObjectProperty>(ArrayProperty->Inner))
			{
				void* ValuePtr = ArrayHelper.GetRawPtr(i);
				//CheckSetType(ArrayProperty->Inner, ValuePtr, temArrayVal);
				UClass* tempClass = tempObjectProperty->PropertyClass;
				UObject* object = NewObject<UObject>(tempClass, tempClass);
				
				if (temArrayVal[0] != '{' && temArrayVal[temArrayVal.Len() - 1] != '}')
				{
					temArrayVal = "{" + temArrayVal + "}";
				}
				object = SetObj(object, temArrayVal);

				UProperty* tempProperty = ArrayProperty->Inner;

				/*UObject* SourceAddr = tempProperty->ContainerPtrToValuePtr<UObject>(ValuePtr);
				SourceAddr = object;*/
				*tempProperty->ContainerPtrToValuePtr<UObject*>(ValuePtr) = object;
				temArrayVal.Empty();
			}
			else
			{
				void* ValuePtr = ArrayHelper.GetRawPtr(i);
				CheckSetType(ArrayProperty->Inner, ValuePtr, temArrayVal);
				temArrayVal.Empty();
			}
		}
	}
	else if (UMapProperty* MapProperty = Cast<UMapProperty>(Property))
	{
		//----进一步处理map的字符串
		TArray<FString> mapKey;//存放key值
		TArray<FString> mapValue;//存放value值
		FString mapK;//临时存放mapkey值
		FString mapV;//临时存放mapvalue值

		//去掉前后的大括号
		value.RemoveAt(0, 1);
		value.RemoveAt(value.Len()-1, 1);

		int flagForLeft = 0;//标记左中括号

		//拆分key和value
		for (int i = 0; i < value.Len(); i++)
		{
			if (value[i] == '[')
			{
				flagForLeft++;
				continue;
			}
			if (value[i] == ']')
			{
				flagForLeft--;
				continue;
			}
			if (flagForLeft && value[i] != ',')
			{
				mapK = mapK + value[i];
			}
			else if(value[i] != '=' && value[i] != ',')
			{
				mapV = mapV + value[i];
			}
			if (value[i] == ',')
			{
				mapKey.Add(mapK);
				mapValue.Add(mapV);
				mapK.Empty();
				mapV.Empty();
			}
		}

		FScriptMapHelper MapHelper(MapProperty, MapProperty->ContainerPtrToValuePtr<void>(Object));
		MapHelper.EmptyValues();//清空原map
		//根据目标Map设置新Map的大小
		for (auto& i : mapKey)
		{
			MapHelper.AddDefaultValue_Invalid_NeedsRehash();
		}
		//设置key和value的值
		for (int i = 0; i < mapKey.Num(); i++)
		{
			CheckSetType(MapProperty->KeyProp, MapHelper.GetKeyPtr(i), mapKey[i]);
			CheckSetType(MapProperty->ValueProp, MapHelper.GetKeyPtr(i), mapValue[i]);
		}
	}
	else if (UStructProperty* StructProperty = Cast<UStructProperty>(Property))
	{
		if (StructProperty->Struct == TBaseStructure<FVector>::Get())
		{
			FString tempFv;
			TArray<float> Fv;
			for (int i = 0; i < value.Len(); i++)
			{
				if ((value[i] >= '0' && value[i] <= '9') || value[i] == '.')
				{
					tempFv = tempFv + value[i];
				}
				else if(value[i] == ',')
				{
					Fv.Add(FCString::Atof(*tempFv));
					tempFv.Empty();
					continue;
				}
			}
			SetPropertyValue(Property, Object, FVector(Fv[0], Fv[1], Fv[2]));
		}
		else if (StructProperty->Struct == TBaseStructure<FRotator>::Get())
		{
			FString tempFr;
			TArray<float> Fr;
			for (int i = 0; i < value.Len(); i++)
			{
				if ((value[i] >= '0' && value[i] <= '9') || value[i] == '.')
				{
					tempFr = tempFr + value[i];
				}
				else if (value[i] == ',')
				{
					Fr.Add(FCString::Atof(*tempFr));
					tempFr.Empty();
					continue;
				}
			}
			SetPropertyValue(Property, Object, FRotator(Fr[0], Fr[1], Fr[2]));
		}
		else if (StructProperty->Struct == TBaseStructure<FSoftObjectPath>::Get())
		{
			value.RemoveAt(0, 1);
			value.RemoveAt(value.Len() - 1, 1);
			SetPropertyValue(Property, Object, FSoftObjectPath(value));
		}
		else if (StructProperty->Struct == TBaseStructure<FSoftClassPath>::Get())
		{
			value.RemoveAt(0, 1);
			value.RemoveAt(value.Len() - 1, 1);
			SetPropertyValue(Property, Object, FSoftClassPath(value));
		}
	}
	else if (USetProperty* SetProperty = Cast<USetProperty>(Property))
	{
		//----进一步处理m字符串
		TArray<FString> setKey;//存放key值

		//去掉前后的大括号
		value.RemoveAt(0, 1);
		value.RemoveAt(value.Len() - 1, 1);

		FScriptSetHelper setHelper(SetProperty, SetProperty->ContainerPtrToValuePtr<void>(Object));
		
		//按照逗号拆分
		FString tempFv="";
		for (int i = 0; i < value.Len(); i++)
		{
			if (value[i] != ',')
			{
				tempFv += value[i];
			}
			else if (value[i] == ',')
			{
				//去掉=true
				//tempFv.RemoveAt(0, 1);
				tempFv.RemoveAt(tempFv.Len() - 5, 5);

				setKey.Add(tempFv);
				tempFv.Empty();
				continue;
			}
		}

		setHelper.EmptyElements();

		for (int i = 0; i < setKey.Num(); i++)
		{	
			setHelper.AddUninitializedValue();
			void* valuePtr = setHelper.GetElementPtr(i);
			CheckSetType(SetProperty->ElementProp, valuePtr, setKey[i]);
		}
	}
	else if (UEnumProperty* EnumProperty = Cast<UEnumProperty>(Property))
	{
		UEnum* tempEnum = EnumProperty->GetEnum();
		int32 strint = FCString::Atoi(*value);
		FName name = tempEnum->GetNameByValue(strint);
		SetPropertyValue(Property, Object, strint);
	}
	else if (UObjectProperty* ObjectProperty = Cast<UObjectProperty>(Property))
	{
		if (value[0] != '{' && value[value.Len()-1] != '}')
		{
			value = "{" + value + "}";
		}
		UObject* object = GetPropertyValue<UObject*>(ObjectProperty, Object);
		if (object == NULL)
		{
			object = NewObject<UObject>(ObjectProperty->PropertyClass, ObjectProperty->PropertyClass);
		}
		SetObj(object, value);
	}
}

UObject* UObjectToLuaParser::SetObj(UObject* object, FString nameAndValue)
{
	UObject* Object = object;

	nameAndValue.RemoveAt(0, 1);
	nameAndValue.RemoveAt(nameAndValue.Len() - 1, 1);
	FString name;
	FString value;
	TArray<FString> nameArray;
	TArray<FString> valueArray;
	TMap<FString, FString> NaVMap;
	int flags = 0;
	int leftBigPara = 0;
	int flagForApo = 0;

	//把字符串拆好 放进map里
	for (int i = 0; i < nameAndValue.Len(); i++)
	{ 

		if (nameAndValue[i] == '=')
		{
			flags++;
			if (flags > 1)
			{
				value += nameAndValue[i];
			}
		}

		if (nameAndValue[i] != '=')
		{
			if (nameAndValue[i] == '}')
			{
				leftBigPara--;
			}

			if (flags)//等号数量大于零
			{
				value += nameAndValue[i];
			}
			else
			{
				name += nameAndValue[i];
			}

			if (leftBigPara == 0)
			{
				if (nameAndValue[i] == '}')
				{
					i++;
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}

				if (flags == 1 && nameAndValue[i] == ',')
				{
					value.RemoveAt(value.Len() - 1, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}

				if (flags >= 1 && leftBigPara == 0 && nameAndValue[i] == ',' && nameAndValue[i - 1] == '\'')
				{
					value.RemoveAt(value.Len() - 1, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}
			}
			continue;
		}
		else
		{
			if (nameAndValue[i + 1] == '{')
			{
				leftBigPara++;
				if (nameAndValue[i] != '=')
				{
					value += nameAndValue[i];
				}
			}
		}
	}

	if (object==NULL || object->GetClass() == NULL)
	{
		return object;
	}
	//开始set
	for (TFieldIterator<UProperty> PropertyIterator(Object->GetClass()); PropertyIterator; ++PropertyIterator)
	{
		UProperty* Property = *PropertyIterator;
		FString PropertyName = Property->GetName();

		for (int i = 0; i < NaVMap.Num(); i++)
		{
			if (PropertyName == nameArray[i])
			{
				CheckSetType(Property, Object, valueArray[i]);
				break;
			}
		}
	}

	return Object;
}

FString UObjectToLuaParser::UObjectToLuaString(UObject* Object, bool DefaultAsEmpty)
{
	return FString::Printf(TEXT("return %s"), *ToObjectStr(Object, DefaultAsEmpty));
}

FString UObjectToLuaParser::UObjectToLuaStringWithIgnore(UObject * Object, FString Ignore, bool DefaultAsEmpty)
{
	TArray<FString> ignoreArray;
	/*void* object = Cast<void>(Object);*/
	FString MatchStr;
	FString RestStr = Ignore;
	while (RestStr.Split(",", &MatchStr, &RestStr))
	{
		ignoreArray.Add(MatchStr);
	}
	ignoreArray.Add(RestStr);

	if (ignoreArray.Num() <= 0)
	{
		return UObjectToLuaParser::UObjectToLuaString(Object, DefaultAsEmpty);
	}

	FString TotalALLNames;
	int ElNum = 0;

	//遍历所有被UProperty标记的成员
	for (TFieldIterator<UProperty> PropertyIterator(Object->GetClass()); PropertyIterator; ++PropertyIterator)
	{
		UProperty* Property = *PropertyIterator;
		FString PropertyName = Property->GetName();

		//判断需要忽略的属性名称
		if (ignoreArray.Contains(PropertyName))
		{
			continue;
		}

		//判断UProperty类型
		FString KVStr = CheckUproperType(Property, Object, DefaultAsEmpty);
		if (!KVStr.IsEmpty())
		{
			if (ElNum > 0)
			{
				TotalALLNames.Append(",");
			}
			TotalALLNames.Append(KVStr);
			ElNum++;
		}
	}
	if (DefaultAsEmpty && TotalALLNames.IsEmpty())
	{
		return FString();
	}
	else
	{
		return FString::Printf(TEXT("return {%s}"), *TotalALLNames);
	}
}

FString UObjectToLuaParser::UObjectToCSV(UObject * Object, bool DefaultAsEmpty)
{
	FString csv = CsvFormat(ToObjectStr(Object, DefaultAsEmpty));
	csv.RemoveAt(0, 1);
	csv.RemoveAt(csv.Len() - 1, 1);
	return csv;
}

FString UObjectToLuaParser::UObjectToCSVwithIgnore(UObject * Object, FString Ignore, bool DefaultAsEmpty)
{
	FString csv = CsvFormat(ToObjectStr(Object, DefaultAsEmpty));
	csv.RemoveAt(0, 1);
	csv.RemoveAt(csv.Len()-1, 1);
	return csv;
}

FString UObjectToLuaParser::GetAimValue(UObject* Object, FString Aim)
{
	FString TotalALLNames;

	//遍历所有被UProperty标记的成员
	for (TFieldIterator<UProperty> PropertyIterator(Object->GetClass()); PropertyIterator; ++PropertyIterator)
	{
		UProperty* Property = *PropertyIterator;
		FString PropertyName = Property->GetName();

		if (Aim == PropertyName)
		{
			TotalALLNames = UObjectToLuaParser::CheckUproperType(Property, Object);
			break;
		}
	}
	
	return TotalALLNames;
}

UObject* UObjectToLuaParser::SetAimValue(UClass* className, FString Aim, FString nameAndValue)
{
	if (nameAndValue[0] == '"' && nameAndValue[nameAndValue.Len() - 1] == '"')
	{
		nameAndValue.RemoveAt(0, 1);
		nameAndValue.RemoveAt(nameAndValue.Len() - 1, 1);
	}
	for (int i = 0; i < nameAndValue.Len(); i++)
	{
		if (nameAndValue[i] == '"' && nameAndValue[i + 1] == '"')
		{
			nameAndValue.RemoveAt(i, 1);
			i++;
		}
	}

	UObject* Object = NewObject<UObject>(className, className);

	//如果有return开头的话就去掉
	nameAndValue = nameAndValue.Replace(TEXT("return"), TEXT(""));

	//去掉前后最外层的大括号
	if (nameAndValue[0] == '{')
	{
		nameAndValue.RemoveAt(0, 1);
		nameAndValue.RemoveAt(nameAndValue.Len() - 1, 1);
	}

	FString name;//临时存放变量名
	FString value;//临时存放变量值
	TArray<FString> nameArray;//变量名的数组
	TArray<FString> valueArray;//变量值的数组
	TMap<FString, FString> NaVMap;
	int flags = 0;//标记等号
	int leftBigPara = 0;//标记{

	//把字符串拆好 放进两个数组里
	for (int i = 0; i < nameAndValue.Len(); i++)
	{

		if (nameAndValue[i] == '=')
		{
			flags++;
			if (flags > 1)
			{
				value += nameAndValue[i];
			}
		}

		if (nameAndValue[i] != '=')
		{
			if (nameAndValue[i] == '}')
			{
				leftBigPara--;
			}

			if (flags)//等号数量大于零
			{
				value += nameAndValue[i];
			}
			else
			{
				name += nameAndValue[i];
			}

			if (leftBigPara == 0)
			{
				if (nameAndValue[i] == '}')
				{
					i++;
					//value.RemoveAt(0, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}

				if (flags == 1 && nameAndValue[i] == ',')
				{
					value.RemoveAt(value.Len() - 1, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}

				if (flags >= 1 && leftBigPara == 0 && nameAndValue[i] == ',' && nameAndValue[i - 1] == '\'')
				{
					value.RemoveAt(value.Len() - 1, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}
			}
			continue;
		}
		else
		{
			if (nameAndValue[i + 1] == '{')
			{
				leftBigPara++;
				if (nameAndValue[i] != '=')
				{
					value += nameAndValue[i];
				}
			}
		}
	}

	//开始set
	for (TFieldIterator<UProperty> PropertyIterator(Object->GetClass()); PropertyIterator; ++PropertyIterator)
	{
		UProperty* Property = *PropertyIterator;
		FString PropertyName = Property->GetName();

 		for (int i = 0; i < NaVMap.Num(); i++)
		{
			if (PropertyName == nameArray[i] && nameArray[i] == Aim)
			{
				CheckSetType(Property, Object, valueArray[i]);
				break;
			}
		}

	}

	return Object;
}

UObject * UObjectToLuaParser::LuaStringToUObject(UClass * className, FString nameAndValue)
{

	UObject* Object = NewObject<UObject>(className, className);
	Object = UObjectToLuaParser::LuaStringToSetUObject(Object, nameAndValue);
	return Object;
}

UObject * UObjectToLuaParser::LuaStringToSetUObject(UObject * objcet, FString nameAndValue)
{
	UObject* Object = objcet;

	//如果有return开头的话就去掉
	nameAndValue = nameAndValue.Replace(TEXT("return"), TEXT(""));

	//去掉前后最外层的大括号
	if (nameAndValue[0] == '{')
	{
		nameAndValue.RemoveAt(0, 1);
		nameAndValue.RemoveAt(nameAndValue.Len() - 1, 1);
	}

	FString name;//临时存放变量名
	FString value;//临时存放变量值
	TArray<FString> nameArray;//变量名的数组
	TArray<FString> valueArray;//变量值的数组
	TMap<FString, FString> NaVMap;
	int flags = 0;//标记等号
	int leftBigPara = 0;//标记{

	//把字符串拆好 放进两个数组里
	for (int i = 0; i < nameAndValue.Len(); i++)
	{

		if (nameAndValue[i] == '=')
		{
			flags++;
			if (flags > 1)
			{
				value += nameAndValue[i];
			}
		}
		if (nameAndValue[i] == '{' && nameAndValue[i-1] == ',')
		{
			leftBigPara++;
		
		}

		if (nameAndValue[i] != '=')
		{
			if (nameAndValue[i] == '}')
			{
				leftBigPara--;
			}

			if (flags)//等号数量大于零
			{
				value += nameAndValue[i];
			}
			else
			{
				name += nameAndValue[i];
			}

			if (leftBigPara == 0)
			{
				if (nameAndValue[i] == '}')
				{
					i++;
					//value.RemoveAt(0, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}

				if (flags == 1 && nameAndValue[i] == ',')
				{
					value.RemoveAt(value.Len() - 1, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}

				if (flags >= 1 && leftBigPara == 0 && nameAndValue[i] == ',' && nameAndValue[i - 1] == '\'')
				{
					value.RemoveAt(value.Len() - 1, 1);
					nameArray.Add(name);
					valueArray.Add(value);
					NaVMap.Add(name, value);
					name.Empty();
					value.Empty();
					leftBigPara = 0;
					flags = 0;
					continue;
				}
			}
			continue;
		}
		else
		{
			if (nameAndValue[i + 1] == '{')
			{
				leftBigPara++;
				if (nameAndValue[i + 2] == '{')
				{
					leftBigPara++;
				}
				if (nameAndValue[i] != '=')
				{
					value += nameAndValue[i];
				}
			}
		}
	}

	//开始set
	for (TFieldIterator<UProperty> PropertyIterator(Object->GetClass()); PropertyIterator; ++PropertyIterator)
	{
		UProperty* Property = *PropertyIterator;
		FString PropertyName = Property->GetName();

		for (int i = 0; i < NaVMap.Num(); i++)
		{
			if (PropertyName == nameArray[i])
			{
				CheckSetType(Property, Object, valueArray[i]);
				break;
			}
		}

	}

	return Object;
}

UObject * UObjectToLuaParser::CSVToUObject(UClass* className, FString nameAndValue)
{
	if (nameAndValue[0] == '"' && nameAndValue[nameAndValue.Len() - 1] == '"')
	{
		nameAndValue.RemoveAt(0, 1);
		nameAndValue.RemoveAt(nameAndValue.Len() - 1, 1);
	}
	for (int i = 0; i < nameAndValue.Len(); i++)
	{
		if (nameAndValue[i] == '"' && nameAndValue[i + 1] == '"')
		{
			nameAndValue.RemoveAt(i, 1);
			i++;
		}
	}
	return UObjectToLuaParser::LuaStringToUObject(className, nameAndValue);
}

UObject * UObjectToLuaParser::CSVToSetUObject(UObject* objcet, FString nameAndValue)
{
	if (nameAndValue[0] == '"' && nameAndValue[nameAndValue.Len()-1] == '"')
	{
		nameAndValue.RemoveAt(0, 1);
		nameAndValue.RemoveAt(nameAndValue.Len()-1, 1);
	}
	for (int i = 0; i < nameAndValue.Len(); i++)
	{
		if (nameAndValue[i] == '"' && nameAndValue[i + 1] == '"')
		{
			nameAndValue.RemoveAt(i, 1);
			i++;
		}
	}
	return UObjectToLuaParser::LuaStringToSetUObject(objcet, nameAndValue);
}

UObject* UObjectToLuaParser::CreateObject(UClass* className)
{
	UObject* Object = NewObject<UObject>(className, className);
	return Object;
}

FString UObjectToLuaParser::CsvFormat(FString Str)
{
	FString csv = Str;
	int32 i = 0;
	int32& index = i;
	if (csv.Contains(TEXT(","), ESearchCase::CaseSensitive, ESearchDir::FromStart)
		|| csv.Contains(TEXT("\""), ESearchCase::CaseSensitive, ESearchDir::FromStart)
		|| csv.Contains(TEXT("\n"), ESearchCase::CaseSensitive, ESearchDir::FromStart))
	{
		for (int j = 0; j < csv.Len(); j++)
		{
			if (csv[j] == '"')
			{
				csv.InsertAt(j, '"');
				j++;
			}
		}
		csv.InsertAt(0, "\"");
		csv.InsertAt(csv.Len(), "\"");
	}
	return csv;
}

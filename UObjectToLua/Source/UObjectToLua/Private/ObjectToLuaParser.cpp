#include "ObjectToLuaParser.h"

FString CheckUproperType(UProperty* Property, void* Object);//重载函数，已经是Uproperty的object是void*类型，无法转换成UObject*，需要重载函数
FString CheckUproperType(UProperty* Property, UObject* Object);//检查Object的UProperty的类型并返回其值的FString
FString CheckUproperTypeForMap(UProperty* Property, void* Object);//检查Map的Key的类型，key的返回必须加上[]，而且key可以是各种基本类型，单独处理
void CheckSetType(UProperty* Property, void* Object, FString value);//检查Object的Uproperty的类型并把value字符串转换成对应值并赋值
UObject* SetObj(UObject* object, FString nameAndValue);//Object的UObjectProperty赋值用，返回一个UObject*
FString CheckUproperTypeForVal(UProperty* Property, UObject* Object);

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

FString CheckUproperType(UProperty* Property, UObject* Object)
{
	if (Cast<UBoolProperty>(Property))
	{
		FString tempName = Property->GetName();
		bool tempBool = GetPropertyValue<bool>(Property, Object);
		FString boolString = tempBool ? TEXT("true") : TEXT("false");

		FString Text = tempName + "=" + boolString + ',';
		return Text;
	}
	else if (Cast<UIntProperty>(Property))
	{
		FString tempName = Property->GetName();
		int32 tempInt = GetPropertyValue<int>(Property, Object);
		FString temptempString = FString::FromInt(GetPropertyValue<int32>(Property, Object));

		FString Text = tempName + "=" + temptempString + ',';
		return Text;
	}
	else if (Cast<UFloatProperty>(Property))
	{
		FString tempName = Property->GetName();
		float tempFloat = GetPropertyValue<float>(Property, Object);
		FString temptempString = FString::SanitizeFloat(tempFloat);

		FString Text = tempName + "=" + temptempString + ',';
		return Text;
	}
	else if (Cast<UStrProperty>(Property))
	{
		FString tempName = Property->GetName();
		FString tempString = GetPropertyValue<FString>(Property, Object);

		FString Text = tempName + "='" + tempString + "'" + ',';
		return Text;
	}
	else if (UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Property))
	{
		FString tempName = Property->GetName();
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayProperty->ContainerPtrToValuePtr<void>(Object));
		FString ArrayAllNames = tempName + "={";
		for (int i = 0; i < ArrayHelper.Num(); i++)
		{
			void* ValuePtr = ArrayHelper.GetRawPtr(i);
			ArrayAllNames += CheckUproperType(ArrayProperty->Inner, ValuePtr);
		}
		ArrayAllNames += "},";
		return ArrayAllNames;
	}
	else if (UMapProperty* MapProperty = Cast<UMapProperty>(Property))
	{
		FString tempName = Property->GetName();
		FScriptMapHelper MapHelper(MapProperty, MapProperty->ContainerPtrToValuePtr<void>(Object));
		FString KeyName;
		FString ValueName;
		FString MapName = tempName + "={";
		for (int i = 0; i < MapHelper.Num(); i++)
		{
			void* KeyObj = MapHelper.GetKeyPtr(i);
			KeyName = CheckUproperTypeForMap(MapProperty->KeyProp, KeyObj);
			ValueName = CheckUproperType(MapProperty->ValueProp, KeyObj);
			MapName += KeyName + "=" + ValueName;
		}
		MapName += "},";
		return MapName;
	}
	else if (UStructProperty* StructProperty = Cast<UStructProperty>(Property))
	{
		if (StructProperty->Struct == TBaseStructure<FVector>::Get())
		{
			FString VectorAll = Property->GetName() + "={";
			FVector vec = GetPropertyValue<FVector>(Property, Object);
			VectorAll = VectorAll + "X=" + FString::SanitizeFloat(vec.X) + ",";
			VectorAll = VectorAll + "Y=" + FString::SanitizeFloat(vec.Y) + ",";
			VectorAll = VectorAll + "Z=" + FString::SanitizeFloat(vec.Z) + ",";
			VectorAll = VectorAll + "},";
			return VectorAll;
		}
		else if (StructProperty->Struct == TBaseStructure<FRotator>::Get())
		{
			FString RotatorAll = Property->GetName() + "={";
			FRotator rot = GetPropertyValue<FRotator>(Property, Object);
			RotatorAll = RotatorAll + "Pitch=" + FString::SanitizeFloat(rot.Pitch) + ",";
			RotatorAll = RotatorAll + "Yaw=" + FString::SanitizeFloat(rot.Yaw) + ",";
			RotatorAll = RotatorAll + "Roll=" + FString::SanitizeFloat(rot.Roll) + ",";
			RotatorAll = RotatorAll + "},";
			return RotatorAll;
		}
	}
	else if (UObjectProperty* ObjectProperty = Cast<UObjectProperty>(Property))
	{
		FString tempName = Property->GetName();
		UObject* tempUObject = GetPropertyValue<UObject*>(ObjectProperty, Object);
		FString UObjectAllNames = tempName + "={";
		if (tempUObject == nullptr)
		{
			return UObjectAllNames += "},";
		}
		for (TFieldIterator<UProperty> IT(tempUObject->GetClass()); IT; ++IT)
		{
			UProperty* Propertyp = *IT;

			//判断UProperty类型
			FString anoTempString = CheckUproperType(Propertyp, tempUObject);
			UObjectAllNames += anoTempString;
			//UObjectAllNames += " ";
		}
		UObjectAllNames += "},";
		return UObjectAllNames;
	}
	return FString();
}

FString CheckUproperTypeForVal(UProperty* Property, UObject* Object)
{
	if (Cast<UBoolProperty>(Property))
	{
		bool tempBool = GetPropertyValue<bool>(Property, Object);
		FString boolString = tempBool ? TEXT("true") : TEXT("false");
		return boolString;
	}
	else if (Cast<UIntProperty>(Property))
	{
		int32 tempInt = GetPropertyValue<int>(Property, Object);
		FString temptempString = FString::FromInt(GetPropertyValue<int32>(Property, Object));
		return temptempString;
	}
	else if (Cast<UFloatProperty>(Property))
	{
		float tempFloat = GetPropertyValue<float>(Property, Object);
		FString temptempString = FString::SanitizeFloat(tempFloat);
		return temptempString;
	}
	else if (Cast<UStrProperty>(Property))
	{
		FString tempString = GetPropertyValue<FString>(Property, Object);
		return tempString;
	}
	return FString();
}

FString CheckUproperType(UProperty* Property, void* Object)
{
	if (Cast<UBoolProperty>(Property))
	{
		FString tempName = Property->GetName();
		bool tempBool = GetPropertyValue<bool>(Property, Object);

		FString boolString = tempBool ? TEXT("true") : TEXT("false");
		boolString += "," ;
		return boolString;
	}
	else if (Cast<UIntProperty>(Property))
	{
		FString tempName = Property->GetName();
		int32 tempInt = GetPropertyValue<int>(Property, Object);
		
		FString temptempString = FString::FromInt(GetPropertyValue<int32>(Property, Object)) + ',';
		return temptempString;
	}
	else if (Cast<UFloatProperty>(Property))
	{
		FString tempName = Property->GetName();
		float tempFloat = GetPropertyValue<float>(Property, Object);

		FString temptempString = FString::SanitizeFloat(GetPropertyValue<float>(Property, Object)) + ',';
		return temptempString;
	}
	else if (Cast<UStrProperty>(Property))
	{
		FString tempName = Property->GetName();

		FString tempString ="'" + GetPropertyValue<FString>(Property, Object) + "'" + ',';
		return tempString;
	}
	else if (UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Property))
	{
		FString tempName = Property->GetName();
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayProperty->ContainerPtrToValuePtr<void>(Object));
		FString ArrayAllNames = tempName + "={";
		for (int i = 0; i < ArrayHelper.Num(); i++)
		{
			void* ValuePtr = ArrayHelper.GetRawPtr(i);
			ArrayAllNames += CheckUproperType(ArrayProperty->Inner, ValuePtr);
		}
		ArrayAllNames += "},";
		return ArrayAllNames;
	}
	else if (UMapProperty* MapProperty = Cast<UMapProperty>(Property))
	{
		FString tempName = Property->GetName();
		FScriptMapHelper MapHelper(MapProperty, MapProperty->ContainerPtrToValuePtr<void>(Object));
		FString KeyName;
		FString ValueName;
		FString MapName = tempName + "={";
		for (int i = 0; i < MapHelper.Num(); i++)
		{
			void* KeyObj = MapHelper.GetKeyPtr(i);
			KeyName = CheckUproperTypeForMap(MapProperty->KeyProp, KeyObj);
			ValueName = CheckUproperType(MapProperty->ValueProp, KeyObj);
			MapName += KeyName + " = " + ValueName;
		}
		MapName += "},";
		return MapName;
	}
	else if (UStructProperty* StructProperty = Cast<UStructProperty>(Property))
	{
		if (StructProperty->Struct == TBaseStructure<FVector>::Get())
		{
			FString VectorAll = Property->GetName() + "={";
			FVector vec = GetPropertyValue<FVector>(Property, Object);
			VectorAll = VectorAll + "X = " + FString::SanitizeFloat(vec.X) + ",";
			VectorAll = VectorAll + "Y = " + FString::SanitizeFloat(vec.Y) + ",";
			VectorAll = VectorAll + "Z = " + FString::SanitizeFloat(vec.Z) + ",";
			VectorAll = VectorAll + "},";
			return VectorAll;
		}
		else if (StructProperty->Struct == TBaseStructure<FRotator>::Get())
		{
			FString RotatorAll = Property->GetName() + "={";
			FRotator rot = GetPropertyValue<FRotator>(Property, Object);
			RotatorAll = RotatorAll + "Pitch = " + FString::SanitizeFloat(rot.Pitch) + ",";
			RotatorAll = RotatorAll + "Yaw = " + FString::SanitizeFloat(rot.Yaw) + ",";
			RotatorAll = RotatorAll + "Roll = " + FString::SanitizeFloat(rot.Roll) + ",";
			RotatorAll = RotatorAll + "},";
			return RotatorAll;
		}

	}
	else if (UObjectProperty* ObjectProperty = Cast<UObjectProperty>(Property))
	{
		FString tempName;
		UObject* tempUObject = GetPropertyValue<UObject*>(ObjectProperty, Object);
		
		if (tempUObject == nullptr)
		{
			return tempName + "={},";
		}

		tempName += UObjectToLuaParser::UObjectToLuaString(tempUObject);
		return tempName + ",";
	}
	return FString();
}

FString CheckUproperTypeForMap(UProperty* Property, void* Object)
{
	if (Cast<UBoolProperty>(Property))
	{
		FString tempName = Property->GetName();
		bool tempBool = GetPropertyValue<bool>(Property, Object);
		FString boolString = tempBool ? TEXT("true") : TEXT("false");

		FString Text = "[" + boolString + "]";
		return Text;
	}
	else if (Cast<UIntProperty>(Property))
	{
		FString tempName = Property->GetName();
		int32 tempInt = GetPropertyValue<int>(Property, Object);
		FString temptempString = FString::FromInt(GetPropertyValue<int32>(Property, Object));

		FString Text = "[" + temptempString + "]";
		return Text;
	}
	else if (Cast<UFloatProperty>(Property))
	{
		FString tempName = Property->GetName();
		float tempFloat = GetPropertyValue<float>(Property, Object);
		FString temptempString = FString::SanitizeFloat(GetPropertyValue<float>(Property, Object));

		FString Text = "[" + temptempString + "]";
		return Text;
	}
	else if (Cast<UStrProperty>(Property))
	{
		FString tempName = Property->GetName();
		FString tempString = GetPropertyValue<FString>(Property, Object);

		FString Text = "[" + tempString + "]";
		return Text;
	}
	else if (UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Property))
	{
		FString tempName = Property->GetName();
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayProperty->ContainerPtrToValuePtr<void>(Object));
		FString ArrayAllNames = tempName + "={";
		for (int i = 0; i < ArrayHelper.Num(); i++)
		{
			void* ValuePtr = ArrayHelper.GetRawPtr(i);
			ArrayAllNames += CheckUproperType(ArrayProperty->Inner, ValuePtr);
		}
		ArrayAllNames += "},";
		return ArrayAllNames;
	}
	else if (UMapProperty* MapProperty = Cast<UMapProperty>(Property))
	{
		FString tempName = Property->GetName();
		FScriptMapHelper MapHelper(MapProperty, MapProperty->ContainerPtrToValuePtr<void>(Object));
		FString KeyName;
		FString ValueName;
		FString MapName = tempName + "={";
		for (int i = 0; i < MapHelper.Num(); i++)
		{
			void* KeyObj = MapHelper.GetKeyPtr(i);
			KeyName = CheckUproperTypeForMap(MapProperty->KeyProp, KeyObj);
			ValueName = CheckUproperType(MapProperty->ValueProp, KeyObj);
			MapName += KeyName + " = " + ValueName;
		}
		MapName += "},";
		return MapName;
	}
	else if (UStructProperty* StructProperty = Cast<UStructProperty>(Property))
	{
		if (StructProperty->Struct == TBaseStructure<FVector>::Get())
		{
			FString VectorAll = Property->GetName() + "={";
			FVector vec = GetPropertyValue<FVector>(Property, Object);
			VectorAll = VectorAll + "X = " + FString::SanitizeFloat(vec.X) + ",";
			VectorAll = VectorAll + "Y = " + FString::SanitizeFloat(vec.Y) + ",";
			VectorAll = VectorAll + "Z = " + FString::SanitizeFloat(vec.Z) + ",";
			VectorAll = VectorAll + "},";
			return VectorAll;
		}
		else if (StructProperty->Struct == TBaseStructure<FRotator>::Get())
		{
			FString RotatorAll = Property->GetName() + "={";
			FRotator rot = GetPropertyValue<FRotator>(Property, Object);
			RotatorAll = RotatorAll + "Pitch = " + FString::SanitizeFloat(rot.Pitch) + ",";
			RotatorAll = RotatorAll + "Yaw = " + FString::SanitizeFloat(rot.Yaw) + ",";
			RotatorAll = RotatorAll + "Roll = " + FString::SanitizeFloat(rot.Roll) + ",";
			RotatorAll = RotatorAll + "},";
			return RotatorAll;
		}

	}
	else if (UObjectProperty* ObjectProperty = Cast<UObjectProperty>(Property))
	{
		FString tempName = Property->GetName();
		UObject* tempUObject = GetPropertyValue<UObject*>(ObjectProperty, Object);
		tempName = ObjectProperty->GetName();
		UObjectToLuaParser::UObjectToLuaString(tempUObject);
	}
	return FString();
}

void CheckSetType(UProperty* Property, void* Object, FString value)
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

UObject* SetObj(UObject* object, FString nameAndValue)
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

FString UObjectToLuaParser::UObjectToLuaString(UObject* Object)
{
	FString TotalALLNames = "return{";

	//遍历所有被UProperty标记的成员
	for (TFieldIterator<UProperty> PropertyIterator(Object->GetClass()); PropertyIterator; ++PropertyIterator)
	{
		UProperty* Property = *PropertyIterator;
		FString PropertyName = Property->GetName();

		//判断UProperty类型
		TotalALLNames += CheckUproperType(Property, Object);
	}
	TotalALLNames += "}";
//  	UE_LOG(LogTemp, Warning, TEXT("%s"), *TotalALLNames);
	return TotalALLNames;
}

FString UObjectToLuaParser::UObjectToLuaStringWithIgnore(UObject * Object, FString ignore)
{
	TArray<FString> ignoreArray;

	FString tempArray;
	for (int i = 0; i < ignore.Len(); i++)
	{
		if (ignore[i] != ',')
		{
			tempArray += ignore[i];
		}
		else
		{
			ignoreArray.Add(tempArray);
			tempArray.Empty();
		}
	}

	FString TotalALLNames;
	if (ignoreArray.Num() <= 0)
	{
		TotalALLNames = UObjectToLuaParser::UObjectToLuaString(Object);
		return TotalALLNames;
	}

	TotalALLNames = "return{";

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
		TotalALLNames += CheckUproperType(Property, Object);
	}
	TotalALLNames += "}";
// 	UE_LOG(LogTemp, Warning, TEXT("%s"), *TotalALLNames);
	return TotalALLNames;
	
}

FString UObjectToLuaParser::UObjectToCSV(UObject * Object)
{
	FString csv = UObjectToLuaParser::UObjectToLuaString(Object);
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
	csv = csv.Replace(TEXT("return"), TEXT(""));
	csv.RemoveAt(0, 1);
	csv.RemoveAt(csv.Len() - 1, 1);
	return csv;
}

FString UObjectToLuaParser::UObjectToCSVwithIgnore(UObject * Object, FString ignore)
{
	FString csv = UObjectToLuaParser::UObjectToLuaStringWithIgnore(Object, ignore);
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
		csv.InsertAt(0, '"');
		csv.InsertAt(csv.Len(), '"');
	}
	csv = csv.Replace(TEXT("return"), TEXT(""));
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
			TotalALLNames = CheckUproperTypeForVal(Property, Object);
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

FString UObjectToLuaParser::LuaStringToCSV(FString LuaString)
{
	FString csv = LuaString;
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

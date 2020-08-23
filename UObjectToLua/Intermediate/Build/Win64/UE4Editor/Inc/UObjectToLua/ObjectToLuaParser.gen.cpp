// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UObjectToLua/Public/ObjectToLuaParser.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectToLuaParser() {}
// Cross Module References
	UOBJECTTOLUA_API UClass* Z_Construct_UClass_UObjectToLuaParser_NoRegister();
	UOBJECTTOLUA_API UClass* Z_Construct_UClass_UObjectToLuaParser();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_UObjectToLua();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_CreateObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_GetAimValue();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_SetAimValue();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString();
	UOBJECTTOLUA_API UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore();
// End Cross Module References
	void UObjectToLuaParser::StaticRegisterNativesUObjectToLuaParser()
	{
		UClass* Class = UObjectToLuaParser::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateObject", &UObjectToLuaParser::execCreateObject },
			{ "CSVToSetUObject", &UObjectToLuaParser::execCSVToSetUObject },
			{ "CSVToUObject", &UObjectToLuaParser::execCSVToUObject },
			{ "GetAimValue", &UObjectToLuaParser::execGetAimValue },
			{ "LuaStringToCSV", &UObjectToLuaParser::execLuaStringToCSV },
			{ "LuaStringToSetUObject", &UObjectToLuaParser::execLuaStringToSetUObject },
			{ "LuaStringToUObject", &UObjectToLuaParser::execLuaStringToUObject },
			{ "SetAimValue", &UObjectToLuaParser::execSetAimValue },
			{ "UObjectToCSV", &UObjectToLuaParser::execUObjectToCSV },
			{ "UObjectToCSVwithIgnore", &UObjectToLuaParser::execUObjectToCSVwithIgnore },
			{ "UObjectToLuaString", &UObjectToLuaParser::execUObjectToLuaString },
			{ "UObjectToLuaStringWithIgnore", &UObjectToLuaParser::execUObjectToLuaStringWithIgnore },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics
	{
		struct ObjectToLuaParser_eventCreateObject_Parms
		{
			UClass* className;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_className;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCreateObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::NewProp_className = { "className", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCreateObject_Parms, className), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::NewProp_className,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "CreateObject", nullptr, nullptr, sizeof(ObjectToLuaParser_eventCreateObject_Parms), Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_CreateObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_CreateObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics
	{
		struct ObjectToLuaParser_eventCSVToSetUObject_Parms
		{
			UObject* objcet;
			FString nameAndValue;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_nameAndValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_objcet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCSVToSetUObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::NewProp_nameAndValue = { "nameAndValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCSVToSetUObject_Parms, nameAndValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::NewProp_objcet = { "objcet", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCSVToSetUObject_Parms, objcet), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::NewProp_nameAndValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::NewProp_objcet,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "CSVToSetUObject", nullptr, nullptr, sizeof(ObjectToLuaParser_eventCSVToSetUObject_Parms), Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics
	{
		struct ObjectToLuaParser_eventCSVToUObject_Parms
		{
			UClass* className;
			FString nameAndValue;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_nameAndValue;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_className;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCSVToUObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::NewProp_nameAndValue = { "nameAndValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCSVToUObject_Parms, nameAndValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::NewProp_className = { "className", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventCSVToUObject_Parms, className), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::NewProp_nameAndValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::NewProp_className,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "CSVToUObject", nullptr, nullptr, sizeof(ObjectToLuaParser_eventCSVToUObject_Parms), Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics
	{
		struct ObjectToLuaParser_eventGetAimValue_Parms
		{
			UObject* Object;
			FString Aim;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Aim;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventGetAimValue_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::NewProp_Aim = { "Aim", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventGetAimValue_Parms, Aim), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventGetAimValue_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::NewProp_Aim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "GetAimValue", nullptr, nullptr, sizeof(ObjectToLuaParser_eventGetAimValue_Parms), Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_GetAimValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_GetAimValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics
	{
		struct ObjectToLuaParser_eventLuaStringToCSV_Parms
		{
			FString LuaString;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_LuaString;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToCSV_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::NewProp_LuaString = { "LuaString", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToCSV_Parms, LuaString), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::NewProp_LuaString,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "LuaStringToCSV", nullptr, nullptr, sizeof(ObjectToLuaParser_eventLuaStringToCSV_Parms), Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics
	{
		struct ObjectToLuaParser_eventLuaStringToSetUObject_Parms
		{
			UObject* objcet;
			FString nameAndValue;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_nameAndValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_objcet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToSetUObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::NewProp_nameAndValue = { "nameAndValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToSetUObject_Parms, nameAndValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::NewProp_objcet = { "objcet", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToSetUObject_Parms, objcet), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::NewProp_nameAndValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::NewProp_objcet,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "LuaStringToSetUObject", nullptr, nullptr, sizeof(ObjectToLuaParser_eventLuaStringToSetUObject_Parms), Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics
	{
		struct ObjectToLuaParser_eventLuaStringToUObject_Parms
		{
			UClass* className;
			FString nameAndValue;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_nameAndValue;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_className;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToUObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::NewProp_nameAndValue = { "nameAndValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToUObject_Parms, nameAndValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::NewProp_className = { "className", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventLuaStringToUObject_Parms, className), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::NewProp_nameAndValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::NewProp_className,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "LuaStringToUObject", nullptr, nullptr, sizeof(ObjectToLuaParser_eventLuaStringToUObject_Parms), Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics
	{
		struct ObjectToLuaParser_eventSetAimValue_Parms
		{
			UClass* classNAme;
			FString Aim;
			FString nameAndValue;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_nameAndValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Aim;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_classNAme;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventSetAimValue_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_nameAndValue = { "nameAndValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventSetAimValue_Parms, nameAndValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_Aim = { "Aim", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventSetAimValue_Parms, Aim), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_classNAme = { "classNAme", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventSetAimValue_Parms, classNAme), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_nameAndValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_Aim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::NewProp_classNAme,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "SetAimValue", nullptr, nullptr, sizeof(ObjectToLuaParser_eventSetAimValue_Parms), Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_SetAimValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_SetAimValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics
	{
		struct ObjectToLuaParser_eventUObjectToCSV_Parms
		{
			UObject* Object;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToCSV_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToCSV_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "UObjectToCSV", nullptr, nullptr, sizeof(ObjectToLuaParser_eventUObjectToCSV_Parms), Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics
	{
		struct ObjectToLuaParser_eventUObjectToCSVwithIgnore_Parms
		{
			UObject* Object;
			FString ignore;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ignore;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToCSVwithIgnore_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::NewProp_ignore = { "ignore", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToCSVwithIgnore_Parms, ignore), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToCSVwithIgnore_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::NewProp_ignore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "UObjectToCSVwithIgnore", nullptr, nullptr, sizeof(ObjectToLuaParser_eventUObjectToCSVwithIgnore_Parms), Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics
	{
		struct ObjectToLuaParser_eventUObjectToLuaString_Parms
		{
			UObject* Object;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToLuaString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToLuaString_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "UObjectToLuaString", nullptr, nullptr, sizeof(ObjectToLuaParser_eventUObjectToLuaString_Parms), Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics
	{
		struct ObjectToLuaParser_eventUObjectToLuaStringWithIgnore_Parms
		{
			UObject* Object;
			FString ignore;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ignore;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToLuaStringWithIgnore_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::NewProp_ignore = { "ignore", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToLuaStringWithIgnore_Parms, ignore), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectToLuaParser_eventUObjectToLuaStringWithIgnore_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::NewProp_ignore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::Function_MetaDataParams[] = {
		{ "Category", "UTL" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectToLuaParser, nullptr, "UObjectToLuaStringWithIgnore", nullptr, nullptr, sizeof(ObjectToLuaParser_eventUObjectToLuaStringWithIgnore_Parms), Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UObjectToLuaParser_NoRegister()
	{
		return UObjectToLuaParser::StaticClass();
	}
	struct Z_Construct_UClass_UObjectToLuaParser_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectToLuaParser_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_UObjectToLua,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UObjectToLuaParser_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UObjectToLuaParser_CreateObject, "CreateObject" }, // 979165846
		{ &Z_Construct_UFunction_UObjectToLuaParser_CSVToSetUObject, "CSVToSetUObject" }, // 1499345206
		{ &Z_Construct_UFunction_UObjectToLuaParser_CSVToUObject, "CSVToUObject" }, // 2934775134
		{ &Z_Construct_UFunction_UObjectToLuaParser_GetAimValue, "GetAimValue" }, // 3814897325
		{ &Z_Construct_UFunction_UObjectToLuaParser_LuaStringToCSV, "LuaStringToCSV" }, // 1813557837
		{ &Z_Construct_UFunction_UObjectToLuaParser_LuaStringToSetUObject, "LuaStringToSetUObject" }, // 2332429923
		{ &Z_Construct_UFunction_UObjectToLuaParser_LuaStringToUObject, "LuaStringToUObject" }, // 3932459336
		{ &Z_Construct_UFunction_UObjectToLuaParser_SetAimValue, "SetAimValue" }, // 3930077502
		{ &Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSV, "UObjectToCSV" }, // 2988755948
		{ &Z_Construct_UFunction_UObjectToLuaParser_UObjectToCSVwithIgnore, "UObjectToCSVwithIgnore" }, // 3979297507
		{ &Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaString, "UObjectToLuaString" }, // 710900712
		{ &Z_Construct_UFunction_UObjectToLuaParser_UObjectToLuaStringWithIgnore, "UObjectToLuaStringWithIgnore" }, // 1227737860
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectToLuaParser_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ObjectToLuaParser.h" },
		{ "ModuleRelativePath", "Public/ObjectToLuaParser.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectToLuaParser_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectToLuaParser>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectToLuaParser_Statics::ClassParams = {
		&UObjectToLuaParser::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectToLuaParser_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectToLuaParser_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectToLuaParser()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectToLuaParser_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectToLuaParser, 2419990763);
	template<> UOBJECTTOLUA_API UClass* StaticClass<UObjectToLuaParser>()
	{
		return UObjectToLuaParser::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectToLuaParser(Z_Construct_UClass_UObjectToLuaParser, &UObjectToLuaParser::StaticClass, TEXT("/Script/UObjectToLua"), TEXT("UObjectToLuaParser"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectToLuaParser);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

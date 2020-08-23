// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
#ifdef UOBJECTTOLUA_ObjectToLuaParser_generated_h
#error "ObjectToLuaParser.generated.h already included, missing '#pragma once' in ObjectToLuaParser.h"
#endif
#define UOBJECTTOLUA_ObjectToLuaParser_generated_h

#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_SPARSE_DATA
#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLuaStringToCSV) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_LuaString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::LuaStringToCSV(Z_Param_LuaString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_className); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::CreateObject(Z_Param_className); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCSVToSetUObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_objcet); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::CSVToSetUObject(Z_Param_objcet,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCSVToUObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_className); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::CSVToUObject(Z_Param_className,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLuaStringToSetUObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_objcet); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::LuaStringToSetUObject(Z_Param_objcet,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLuaStringToUObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_className); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::LuaStringToUObject(Z_Param_className,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAimValue) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_classNAme); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Aim); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::SetAimValue(Z_Param_classNAme,Z_Param_Aim,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAimValue) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Aim); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::GetAimValue(Z_Param_Object,Z_Param_Aim); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToCSVwithIgnore) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ignore); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToCSVwithIgnore(Z_Param_Object,Z_Param_ignore); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToCSV) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToCSV(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToLuaStringWithIgnore) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ignore); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToLuaStringWithIgnore(Z_Param_Object,Z_Param_ignore); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToLuaString) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToLuaString(Z_Param_Object); \
		P_NATIVE_END; \
	}


#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLuaStringToCSV) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_LuaString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::LuaStringToCSV(Z_Param_LuaString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_className); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::CreateObject(Z_Param_className); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCSVToSetUObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_objcet); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::CSVToSetUObject(Z_Param_objcet,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCSVToUObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_className); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::CSVToUObject(Z_Param_className,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLuaStringToSetUObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_objcet); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::LuaStringToSetUObject(Z_Param_objcet,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLuaStringToUObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_className); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::LuaStringToUObject(Z_Param_className,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAimValue) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_classNAme); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Aim); \
		P_GET_PROPERTY(UStrProperty,Z_Param_nameAndValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UObjectToLuaParser::SetAimValue(Z_Param_classNAme,Z_Param_Aim,Z_Param_nameAndValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAimValue) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Aim); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::GetAimValue(Z_Param_Object,Z_Param_Aim); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToCSVwithIgnore) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ignore); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToCSVwithIgnore(Z_Param_Object,Z_Param_ignore); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToCSV) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToCSV(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToLuaStringWithIgnore) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ignore); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToLuaStringWithIgnore(Z_Param_Object,Z_Param_ignore); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUObjectToLuaString) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UObjectToLuaParser::UObjectToLuaString(Z_Param_Object); \
		P_NATIVE_END; \
	}


#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUObjectToLuaParser(); \
	friend struct Z_Construct_UClass_UObjectToLuaParser_Statics; \
public: \
	DECLARE_CLASS(UObjectToLuaParser, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UObjectToLua"), NO_API) \
	DECLARE_SERIALIZER(UObjectToLuaParser)


#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUObjectToLuaParser(); \
	friend struct Z_Construct_UClass_UObjectToLuaParser_Statics; \
public: \
	DECLARE_CLASS(UObjectToLuaParser, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UObjectToLua"), NO_API) \
	DECLARE_SERIALIZER(UObjectToLuaParser)


#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectToLuaParser(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectToLuaParser) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectToLuaParser); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectToLuaParser); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectToLuaParser(UObjectToLuaParser&&); \
	NO_API UObjectToLuaParser(const UObjectToLuaParser&); \
public:


#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectToLuaParser(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectToLuaParser(UObjectToLuaParser&&); \
	NO_API UObjectToLuaParser(const UObjectToLuaParser&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectToLuaParser); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectToLuaParser); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectToLuaParser)


#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_PRIVATE_PROPERTY_OFFSET
#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_10_PROLOG
#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_PRIVATE_PROPERTY_OFFSET \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_SPARSE_DATA \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_RPC_WRAPPERS \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_INCLASS \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_PRIVATE_PROPERTY_OFFSET \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_SPARSE_DATA \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_INCLASS_NO_PURE_DECLS \
	XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UOBJECTTOLUA_API UClass* StaticClass<class UObjectToLuaParser>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID XGame_Plugins_UObjectToLua_Source_UObjectToLua_Public_ObjectToLuaParser_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

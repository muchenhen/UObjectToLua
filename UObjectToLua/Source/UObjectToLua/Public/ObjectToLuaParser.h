#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/UnrealType.h"
#include "UObject/UnrealType.h"
#include "ObjectToLuaParser.generated.h"

UCLASS()
class UOBJECTTOLUA_API UObjectToLuaParser : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static FString UObjectToLuaString(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static FString UObjectToLuaStringWithIgnore(UObject* Object, FString ignore);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static FString UObjectToCSV(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static FString UObjectToCSVwithIgnore(UObject* Object, FString ignore);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static FString GetAimValue(UObject* Object, FString Aim);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static UObject* SetAimValue(UClass* classNAme, FString Aim, FString nameAndValue);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static UObject* LuaStringToUObject(UClass* className, FString nameAndValue);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static UObject* LuaStringToSetUObject(UObject* objcet, FString nameAndValue);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static UObject* CSVToUObject(UClass* className, FString nameAndValue);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static UObject* CSVToSetUObject(UObject* objcet, FString nameAndValue);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static UObject* CreateObject(UClass* className);

	UFUNCTION(BlueprintCallable, Category = "UTL")
	static FString LuaStringToCSV(FString LuaString);
};
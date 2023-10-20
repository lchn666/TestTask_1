// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/ConstructorHelpers.h"
#include "JsonUtilities.h"
#include "DataHolder.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_API UDataHolder : public UObject
{
	GENERATED_BODY()

public:
	
	void Init(FString FilePath);

	void LoadData();

	bool GetValue(int32 RowIndex, int32 ColumnIndex, int32& Value);

private:

	FString Path;

	bool bLoaded;
	
	TSharedPtr<FJsonObject> JsonObject;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "DataHolder.h"

void UDataHolder::Init(FString FilePath)
{
	Path = FilePath;
	Path = FPaths::ProjectDir() + TEXT("TestTaskInput.json");
}

void UDataHolder::LoadData()
{
	JsonObject = nullptr;
	bLoaded = false;
	
	FString JsonData;

	bLoaded = FFileHelper::LoadFileToString(JsonData, *Path);

	if (!bLoaded)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *Path);
		return;
	}
	
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonData);

	if (!FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to deserialize data."));
		bLoaded = false;
		return;
	}

	UE_LOG(LogTemp, Error, TEXT("Data loaded successfully !"));
}

bool UDataHolder::GetValue(int32 RowIndex, int32 ColumnIndex, int32& Value)
{
	if (!bLoaded || !JsonObject) return false;
	
	const TArray<TSharedPtr<FJsonValue>>* matrix;
	
	if (JsonObject->TryGetArrayField("Array",  matrix))
	{
		if (RowIndex < matrix->Num())
		{
			const TArray<TSharedPtr<FJsonValue>>* row;
		
			if ((*matrix)[RowIndex]->TryGetArray(row))
			{
				if (ColumnIndex < row->Num())
				{
					(*row)[ColumnIndex]->TryGetNumber(Value);

					return true;
				}
			}
		}
	}

	return false;
}

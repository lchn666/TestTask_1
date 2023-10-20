// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UserController.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_API AUserController : public APlayerController
{
	GENERATED_BODY()

public:

	AUserController();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> UIClass;

private:

	UPROPERTY()
	UUserWidget* UI;

	void CreateUI();

	void SetupInputMode();
};

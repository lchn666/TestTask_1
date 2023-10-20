// Fill out your copyright notice in the Description page of Project Settings.


#include "UserController.h"

#include "MyButtonsWidget.h"
#include "Blueprint/UserWidget.h"

AUserController::AUserController()
{
	bShowMouseCursor = true;
}

void AUserController::BeginPlay()
{
	Super::BeginPlay();

	CreateUI();
	SetupInputMode();
}

void AUserController::CreateUI()
{
	if (!UIClass) return;
	
	UI = CreateWidget<UUserWidget>(this, UIClass);

	if (UI)
	{
		UI->AddToViewport();
	}
}

void AUserController::SetupInputMode()
{
	if (UI)
	{
		FInputModeUIOnly InputModeData;
		InputModeData.SetWidgetToFocus(UI->TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

		SetInputMode(InputModeData);
	}
}

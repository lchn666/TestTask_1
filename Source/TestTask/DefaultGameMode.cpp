// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultGameMode.h"
#include "UserController.h"

ADefaultGameMode::ADefaultGameMode()
{
	PlayerControllerClass = AUserController::StaticClass();
}

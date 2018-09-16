// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPS_PrototypeGameMode.h"
#include "FPS_PrototypeHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPS_PrototypeGameMode::AFPS_PrototypeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behavior/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPS_PrototypeHUD::StaticClass();
}

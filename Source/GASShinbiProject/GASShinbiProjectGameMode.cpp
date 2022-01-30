// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASShinbiProjectGameMode.h"
#include "GASShinbiProjectHUD.h"
#include "GASShinbiProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASShinbiProjectGameMode::AGASShinbiProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGASShinbiProjectHUD::StaticClass();
}

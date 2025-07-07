// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDownGameMode.h"
#include "TopDownPlayerController.h"
#include "TopDownCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopDownGameMode::ATopDownGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/Character/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
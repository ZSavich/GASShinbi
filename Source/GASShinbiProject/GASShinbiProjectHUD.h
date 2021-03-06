// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GASShinbiProjectHUD.generated.h"

UCLASS()
class AGASShinbiProjectHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGASShinbiProjectHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


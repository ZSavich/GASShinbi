// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GASSHINBIPROJECT_API ASCharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Components")
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Components")
    UCameraComponent* FollowCamera;
    
public:
	ASCharacterBase();

protected:
	virtual void BeginPlay() override;
    
    void MoveForward(const float Amount);
    void MoveRight(const float Amount);

public:	

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ASCharacterBase::ASCharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(GetRootComponent());

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom);
}

void ASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


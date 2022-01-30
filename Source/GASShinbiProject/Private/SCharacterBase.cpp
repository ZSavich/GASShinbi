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
    ensure(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacterBase::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacterBase::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASCharacterBase::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("Turn", this, &ASCharacterBase::AddControllerYawInput);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASCharacterBase::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ASCharacterBase::StopJumping);
}

void ASCharacterBase::MoveForward(const float Amount)
{
    if(Amount)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Amount);
    }
}

void ASCharacterBase::MoveRight(const float Amount)
{
    if(Amount)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Amount);
    }
}
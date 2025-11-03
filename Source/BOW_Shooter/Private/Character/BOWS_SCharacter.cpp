// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BOWS_SCharacter.h"
#include  "GameFramework/SpringArmComponent.h"
#include  "Camera/CameraComponent.h"
#include "UObject/ObjectMacros.h"

// Sets default values
ABOWS_SCharacter::ABOWS_SCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void ABOWS_SCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABOWS_SCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}


// Called every frame
void ABOWS_SCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABOWS_SCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ABOWS_SCharacter::MoveForward);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

}


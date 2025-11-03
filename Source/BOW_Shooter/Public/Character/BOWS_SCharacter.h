// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "BOWS_SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class BOW_SHOOTER_API ABOWS_SCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABOWS_SCharacter();

protected:
	UPROPERTY(visibleAnywhere)
	USpringArmComponent* SpringArmComp;

	
	
	
	UPROPERTY(visibleAnywhere)
	UCameraComponent* CameraComp; //3th person camera component
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

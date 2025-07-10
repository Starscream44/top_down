// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Type.generated.h"

UENUM(BlueprintType)
enum class EMovementState:uint8
{
	Aim_state UMETA(DisplayName = "Aim State"),
	Walk_state UMETA(DisplayName = "Walk State"),
	Run_state UMETA(DisplayName = "Run State"),

};

USTRUCT(BlueprintType)
struct FCharacterSpeed
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float WalkSpeed = 300.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RunSpeed = 600.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float AimSpeed = 200.f;

};

UCLASS()
class TOPDOWN_API UType : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};

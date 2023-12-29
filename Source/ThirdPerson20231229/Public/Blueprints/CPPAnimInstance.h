// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSON20231229_API UCPPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void  NativeUpdateAnimation(float Deltaseconds) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stat")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stat")
	bool ShouldMove;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stat")
	bool IsFalling;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stat")
	FVector Velocity;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprints/CPPAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCPPAnimInstance::NativeUpdateAnimation(float Deltaseconds)
{
	Super::NativeUpdateAnimation(Deltaseconds);
	
	ACharacter* MyCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(MyCharacter))
	{
		Speed = MyCharacter->GetCharacterMovement()->Velocity.Size2D();

	}
	
}

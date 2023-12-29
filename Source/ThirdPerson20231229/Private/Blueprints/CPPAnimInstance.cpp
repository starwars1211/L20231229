// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprints/CPPAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCPPAnimInstance::NativeUpdateAnimation(float Deltaseconds)
{
	Super::NativeUpdateAnimation(Deltaseconds); //부모 호출
	
	ACharacter* MyCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(MyCharacter))
	{
		Velocity = MyCharacter->GetCharacterMovement()->Velocity;
		GroundSpeed = MyCharacter->GetCharacterMovement()->Velocity.Size();
		ShouldMove = (GroundSpeed >3.0f) && UKismetMathLibrary::NotEqual_VectorVector
		(MyCharacter->GetCharacterMovement()->GetCurrentAcceleration(),FVector::ZeroVector, 0);
		IsFalling = MyCharacter->GetCharacterMovement()->IsFalling();

	}
	
}

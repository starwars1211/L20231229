// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprints/TPC.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ATPC::ATPC()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));

}

// Called when the game starts or when spawned
void ATPC::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UEIA = Cast< UEnhancedInputComponent>(PlayerInputComponent);
	if (UEIA)
	{
		UEIA->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ATPC::Jump);
		UEIA->BindAction(IA_Jump, ETriggerEvent::Canceled, this, &ATPC::StopJumping);

		UEIA->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ATPC::Move);
		UEIA->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ATPC::Look);

	}

}

void ATPC::Move(const FInputActionValue& Value)
{
	FVector2D Dir = Value.Get<FVector2D>();

	FRotator CameraRotation = GetControlRotation();
	FRotator DirectionRotatiom = FRotator(0,CameraRotation.Yaw,0);

	FVector FowardVector = UKismetMathLibrary::GetForwardVector(DirectionRotatiom);
	FVector RightVector = UKismetMathLibrary::GetRightVector(DirectionRotatiom);

	AddMovementInput(FowardVector, Dir.Y);
	AddMovementInput(RightVector, Dir.X);
}

void ATPC::Look(const FInputActionValue& Value)
{
	FVector2D Rotation = Value.Get<FVector2D>();
	AddControllerYawInput(Rotation.X);
	AddControllerPitchInput(Rotation.Y);
}


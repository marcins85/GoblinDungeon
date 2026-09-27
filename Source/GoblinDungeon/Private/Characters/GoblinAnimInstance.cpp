// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GoblinAnimInstance.h"
#include "Characters/GoblinCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UGoblinAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	GoblinCharacter = Cast<AGoblinCharacter>(TryGetPawnOwner());
	if (GoblinCharacter)
	{
		GoblinCharacterMovement = GoblinCharacter->GetCharacterMovement();
	}
}

void UGoblinAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (GoblinCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(GoblinCharacterMovement->Velocity);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// Super는 공식 문법은 아니고 GENERATED_BODY에 포함된 기능
	// C++ 에선 UAnimInstance이 들어가야하는데 Super로 대체
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn))
	{
		Speed = pawn->GetVelocity().Size();
	}
}

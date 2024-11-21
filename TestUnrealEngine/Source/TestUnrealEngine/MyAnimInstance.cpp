// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyCharacter.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Wukong_Skeleton_Montage.Wukong_Skeleton_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> DM(TEXT("AnimMontage'/Game/Animations/Wukong_Dead_Montage.Wukong_Dead_Montage'"));
	if (DM.Succeeded())
	{
		DeadMontage = DM.Object;
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// Super는 공식 문법은 아니고 GENERATED_BODY에 포함된 기능
	// C++ 에선 UAnimInstance이 들어가야하는데 Super로 대체
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<AMyCharacter>(Pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();

			Vertical = Character->UpDownValue;
			Horizontal = Character->LeftRightValue;
		}
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.f);
}

void UMyAnimInstance::PlayDeadMontage()
{
	//Montage_Play(DeadMontage, 1.f);
	UE_LOG(LogTemp, Warning, TEXT("Death animation started."));
}

void UMyAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UMyAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	return FName(FString::Printf(TEXT("Attack%d"), SectionIndex));
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	//UE_LOG(LogTemp, Log, TEXT("AnimNotify_AttackHit"));
	OnAttackHit.Broadcast();
}

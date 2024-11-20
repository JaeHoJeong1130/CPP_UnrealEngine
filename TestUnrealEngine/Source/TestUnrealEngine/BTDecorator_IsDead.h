// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsDead.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UBTDecorator_IsDead : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_IsDead();

	bool DeadCheck();

	UPROPERTY(VisibleAnywhere)
	class UMyStatComponent* Stat;
	
};

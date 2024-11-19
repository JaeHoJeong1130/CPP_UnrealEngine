// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMyAIController();

	// ºùÀÇ
	virtual void OnPossess(APawn* InPawn) override;
	// ºùÀÇ ³¡
	virtual void OnUnPossess() override;

private:
	void RandomMove();

private:
	FTimerHandle TimerHandle;
	UPROPERTY()
	class UBehaviorTree* BehaviorTree;

	UPROPERTY()
	class UBlackboardData* BlackboardData;
	
};

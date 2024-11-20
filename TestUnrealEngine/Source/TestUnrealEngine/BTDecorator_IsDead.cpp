// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsDead.h"
#include "MyStatComponent.h"

UBTDecorator_IsDead::UBTDecorator_IsDead()
{
	NodeName = TEXT("IsDead");
}

bool UBTDecorator_IsDead::DeadCheck()
{
	int32 hp = Stat->GetHp();
	UE_LOG(LogTemp, Log, TEXT("remaing Hp : %s"), hp);
	
	if (hp <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

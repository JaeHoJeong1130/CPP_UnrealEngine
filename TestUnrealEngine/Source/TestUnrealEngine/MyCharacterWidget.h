// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindHp(class UMyStatComponent* StatComp);

	void UpdateHp();

private:
	// ����Ʈ ������
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	// �������Ʈ �������� ���������Ŷ� �� ������ ������ ���ش�
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HpBar;
	
};

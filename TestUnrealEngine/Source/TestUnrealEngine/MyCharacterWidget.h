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
	// 스마트 포인터
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	// 블루프린트 툴상으로 만들어줬던거랑 이 변수랑 매핑을 해준다
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HpBar;
	
};

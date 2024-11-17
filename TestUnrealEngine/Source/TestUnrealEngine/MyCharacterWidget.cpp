// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	// 우리는 PB_HpBar를 자동으로 찾게해서 쓰는 만약에 수동으로 해야한다?
	//PB_HpBar123 = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HpBar")));

	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp);
}

void UMyCharacterWidget::UpdateHp()
{
	if(CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}

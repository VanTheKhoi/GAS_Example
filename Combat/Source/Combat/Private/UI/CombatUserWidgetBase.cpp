// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CombatUserWidgetBase.h"
#include "Components/Button.h"

void UCombatUserWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (CloseUIButton)
	{
		CloseUIButton->OnClicked.AddDynamic(this, &UCombatUserWidgetBase::RemoveMainUI); // Callback
	}
}

void UCombatUserWidgetBase::RemoveMainUI()
{
	RemoveFromParent();
	// Hide mouse cursor and disable UI interaction
	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->bShowMouseCursor = false;
		PC->bEnableClickEvents = false;
		PC->bEnableMouseOverEvents = false;	
	}
}

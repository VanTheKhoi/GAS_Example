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
	
	// Set Focus
	SetIsFocusable(true);
	SetKeyboardFocus();
}

FReply UCombatUserWidgetBase::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	// UE_LOG(LogTemp, Warning, TEXT("Key Pressed: %s"), *InKeyEvent.GetKey().ToString());
	RemoveMainUI();
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

FReply UCombatUserWidgetBase::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	RemoveMainUI();
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UCombatUserWidgetBase::RemoveMainUI()
{
	OnExitButtonClick.Broadcast();
	
	UE_LOG(LogTemp, Log, TEXT("RemoveMainUI called in CombatUserWidgetBase"));
	
	RemoveFromParent();
	// Hide mouse cursor and disable UI interaction
	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->bShowMouseCursor = false;
		PC->bEnableClickEvents = false;
		PC->bEnableMouseOverEvents = false;	
	}
}

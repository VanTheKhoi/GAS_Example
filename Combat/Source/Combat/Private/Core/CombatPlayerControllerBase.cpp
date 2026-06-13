// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CombatPlayerControllerBase.h"
#include "UI/CombatUserWidgetBase.h"

void ACombatPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	MainUIWidget = CreateWidget<UUserWidget>(this, MainUIClass);
	
	if (MainUIWidget)
	{
		MainUIWidget->AddToViewport();
		
		// Show mouse cursor and enable UI interaction
		this->bShowMouseCursor = true;
		this->bEnableClickEvents = true;
		this->bEnableMouseOverEvents = true;
				
		FInputModeGameAndUI InputMode;
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		InputMode.SetHideCursorDuringCapture(false);
		this->SetInputMode(InputMode);
	}
}
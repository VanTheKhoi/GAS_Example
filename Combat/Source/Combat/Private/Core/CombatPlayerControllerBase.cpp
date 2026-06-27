// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CombatPlayerControllerBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI/CombatUserWidgetBase.h"

void ACombatPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Add Main UI to viewport
	ShowMainUI();
	
	// Add input mapping context for UI
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (UIMappingContext)
		{
			Subsystem->AddMappingContext(UIMappingContext, 0);
		}
	}
	
	// Cast to CombatUserWidgetBase
	if (MainUIWidget)
	{
		if (UCombatUserWidgetBase* CombatUserWidget = Cast<UCombatUserWidgetBase>(MainUIWidget))
		{
			CombatUserWidget->OnExitButtonClick.AddDynamic(this, &ACombatPlayerControllerBase::ShowPlayerHUD);
		}
	}
}

void ACombatPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (ShowMainUIAction)
		{
			EnhancedInputComponent->BindAction(ShowMainUIAction, ETriggerEvent::Completed, this, &ACombatPlayerControllerBase::ShowMainUI);
		}
	}
}

void ACombatPlayerControllerBase::ShowMainUI()
{
	UE_LOG(LogTemp, Log, TEXT("ShowMainUI called in PlayerController"));
	
	// Check if the main ui widget is in viewport, if not create and add it
	if (!MainUIWidget)
	{
		MainUIWidget = CreateWidget<UUserWidget>(this, MainUI);
	}
	
	if (!MainUIWidget->IsInViewport())
	{
		MainUIWidget->AddToViewport();
		
		// Show mouse cursor and enable UI interaction
		this->bShowMouseCursor = true;
		this->bEnableClickEvents = true;
		this->bEnableMouseOverEvents = true;
		
	}
}

void ACombatPlayerControllerBase::ShowPlayerHUD()
{
	UE_LOG(LogTemp, Log, TEXT("Show Player HUD"));
	
	// Check if the main ui widget is in viewport, if not create and add it
	if (!PlayerHUDWidget)
	{
		PlayerHUDWidget = CreateWidget<UUserWidget>(this, PlayerHUD);
	}
	
	if (!PlayerHUDWidget->IsInViewport())
	{
		PlayerHUDWidget->AddToViewport();
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "CombatPlayerControllerBase.generated.h"

/**
 *
 */

class UInputAction;
class UInputMappingContext;

UCLASS()
class COMBAT_API ACombatPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> MainUIClass;
	
	UPROPERTY()
	UUserWidget* MainUIWidget;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> UIMappingContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ShowMainUIAction;

public:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
	void ShowMainUI();
};

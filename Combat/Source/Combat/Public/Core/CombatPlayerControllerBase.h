// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CombatPlayerControllerBase.generated.h"

/**
 *
 */
UCLASS()
class COMBAT_API ACombatPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> MainUIClass;
	
	UPROPERTY()
	UUserWidget* MainUIWidget;

public:
	virtual void BeginPlay() override;
};

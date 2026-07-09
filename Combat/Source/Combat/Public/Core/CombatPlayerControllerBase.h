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
	TSubclassOf<UUserWidget> MainUI;
	
	UPROPERTY()
	UUserWidget* MainUIWidget;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> PauseUI;
	
	UPROPERTY()
	UUserWidget* PauseUIWidget;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUD;
	
	UPROPERTY()
	UUserWidget* PlayerHUDWidget;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> UIMappingContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ShowMainUIAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor> CombatManagerActor;

public:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
	UFUNCTION()
	void ShowMainUI();
	
	UFUNCTION()
	void ShowPlayerHUD();
	
	UFUNCTION()
	void SpawnCombatManager();
};

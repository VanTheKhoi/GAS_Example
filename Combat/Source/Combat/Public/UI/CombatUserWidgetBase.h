// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CombatUserWidgetBase.generated.h"

/**
 * 
 */

class UTextBlock;
class UButton;

UCLASS()
class COMBAT_API UCombatUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> CloseUIButton;
	
private:
	UFUNCTION()
	void RemoveMainUI();
};

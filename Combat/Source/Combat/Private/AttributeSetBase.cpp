// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

UAttributeSetBase::UAttributeSetBase()
{
	Stamina = 100.f;
}

void UAttributeSetBase::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, Stamina, OldStamina);
}

void UAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, Stamina, COND_None, REPNOTIFY_Always);
}

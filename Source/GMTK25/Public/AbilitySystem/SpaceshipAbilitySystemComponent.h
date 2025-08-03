// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SpaceshipAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GMTK25_API USpaceshipAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

};

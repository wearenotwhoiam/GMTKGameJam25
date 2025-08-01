// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SpaceshipGameplayAbility.generated.h"


UENUM(BlueprintType)
enum class ESpaceshipAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class GMTK25_API USpaceshipGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	//~ Begin UGameplayAbility Interface.

	UPROPERTY(EditDefaultsOnly, Category = "WarriorAbility")
	ESpaceshipAbilityActivationPolicy AbilityActivationPolicy = ESpaceshipAbilityActivationPolicy::OnTriggered;
};

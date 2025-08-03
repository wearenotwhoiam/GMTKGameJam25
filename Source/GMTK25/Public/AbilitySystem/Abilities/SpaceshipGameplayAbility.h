// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SpaceshipGameplayAbility.generated.h"

class UPawnActionComponent;
class USpaceshipAbilitySystemComponent;

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
	virtual bool DoesAbilitySatisfyTagRequirements(const UAbilitySystemComponent& AbilitySystemComponent, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	//~ End UGameplayAbility Interface
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	//~ Begin UGameplayAbility Interface.
	UPROPERTY(EditDefaultsOnly, Category = "Spaceship|Ability")
	ESpaceshipAbilityActivationPolicy AbilityActivationPolicy = ESpaceshipAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Spaceship|Ability")
	UPawnActionComponent* GetPawnActionComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Spaceship|Ability")
	USpaceshipAbilitySystemComponent* GetSpaceshipAbilitySystemComponent() const;
};

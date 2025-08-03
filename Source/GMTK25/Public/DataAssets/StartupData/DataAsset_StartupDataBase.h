// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class USpaceshipGameplayAbility;
class USpaceshipAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class GMTK25_API UDataAsset_StartupDataBase : public UDataAsset
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(USpaceshipAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<USpaceshipGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<USpaceshipGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<USpaceshipGameplayAbility>>& InAbilitiesToGive, USpaceshipAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};

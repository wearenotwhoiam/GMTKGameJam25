// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "SpaceshipStructType.generated.h"
class USpaceshipGameplayAbility;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FPlayerShipAbilitySet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<USpaceshipGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FPlayerSpaceshipToolData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FPlayerShipAbilitySet> DefaultToolAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	UInputMappingContext* WeaponInputMappingContext;
};
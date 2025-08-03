// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemInterface.h"
#include "SpaceshipBasePawn.generated.h"

class USpaceshipAbilitySystemComponent;
class USpaceshipAttributeSet;
class UDataAsset_PlayerShipStartupData;
UCLASS()
class GMTK25_API ASpaceshipBasePawn : public APawn ,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceshipBasePawn();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface.

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	USpaceshipAbilitySystemComponent* SpaceshipAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	USpaceshipAttributeSet* SpaceshipAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_PlayerShipStartupData> CharacterStartupData;
public:
	FORCEINLINE USpaceshipAbilitySystemComponent* GetSpaceshipAbilitySystemComponent() const { return SpaceshipAbilitySystemComponent; }
	
	FORCEINLINE USpaceshipAttributeSet* GetSpaceshipAttributeSet()  const { return SpaceshipAttributeSet; }
};

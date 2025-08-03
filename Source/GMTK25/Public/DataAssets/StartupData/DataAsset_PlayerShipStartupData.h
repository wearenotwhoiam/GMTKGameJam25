// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"
#include "SpaceshipStructType.h"

#include "DataAsset_PlayerShipStartupData.generated.h"

/**
 * 
 */
UCLASS()
class GMTK25_API UDataAsset_PlayerShipStartupData : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(USpaceshipAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData", meta = (TitleProperty = "InputTag"))
	TArray<FPlayerShipAbilitySet> PlayerStartupAbilitySets;

};

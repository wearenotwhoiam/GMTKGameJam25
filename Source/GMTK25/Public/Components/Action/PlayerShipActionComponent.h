// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Components/Action/PawnActionComponent.h"
#include "PlayerShipActionComponent.generated.h"

class APlayerSpaceshipTool;

/**
 * 
 */
UCLASS()
class GMTK25_API UPlayerShipActionComponent : public UPawnActionComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "PlayerShip | Actions")
	APlayerSpaceshipTool* GetPlayerCarriedToolByTag(FGameplayTag InToolTag) const;
};

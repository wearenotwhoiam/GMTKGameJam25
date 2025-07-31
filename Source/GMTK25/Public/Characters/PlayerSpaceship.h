// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Characters/SpaceshipBasePawn.h"
#include "PlayerSpaceship.generated.h"

/**
 * 
 */
UCLASS()
class GMTK25_API APlayerSpaceship : public ASpaceshipBasePawn
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};

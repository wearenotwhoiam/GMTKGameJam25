// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Items/Tools/SpaceshipToolBase.h"
#include "SpaceshipStructType.h"
#include "PlayerSpaceshipTool.generated.h"

/**
 * 
 */
UCLASS()
class GMTK25_API APlayerSpaceshipTool : public ASpaceshipToolBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ToolData")
	FPlayerSpaceshipToolData PlayerSpaceshipToolData;
};

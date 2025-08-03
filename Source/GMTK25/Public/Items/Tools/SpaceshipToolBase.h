// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"
#include "SpaceshipToolBase.generated.h"

class UBoxComponent;
/**
 * 
 */
UCLASS()
class GMTK25_API ASpaceshipToolBase : public AItemBase
{
	GENERATED_BODY()
public:
	ASpaceshipToolBase();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tools")
	UStaticMeshComponent* ToolMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tools")
	UBoxComponent* ToolCollisionBox;
private:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return ToolCollisionBox; }
};

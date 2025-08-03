// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"

#include "PawnActionComponent.generated.h"

class ASpaceshipToolBase;
/**
 * 
 */
UCLASS()
class GMTK25_API UPawnActionComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "PlayerShip | Actions")
	void RegisterSpawnedTool(FGameplayTag InToolTagToRegister, ASpaceshipToolBase* InToolToRegister, bool bRegisterAsEquippedTool = false);

	UFUNCTION(BlueprintCallable, Category = "PlayerShip | Actions")
	ASpaceshipToolBase* GetCharacterCarriedToolByTag(FGameplayTag InToolTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "PlayerShip | Actions")
	FGameplayTag CurrentEquippedToolTag;

	UFUNCTION(BlueprintCallable, Category = "PlayerShip | Actions")
	ASpaceshipToolBase* GetCharacterCurrentEquippedTool() const;
private:
	TMap<FGameplayTag, ASpaceshipToolBase*> CharacterCarriedToolMap;

};

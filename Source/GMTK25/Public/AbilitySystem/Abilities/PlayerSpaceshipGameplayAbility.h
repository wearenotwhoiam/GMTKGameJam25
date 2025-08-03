// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SpaceshipGameplayAbility.h"
#include "PlayerSpaceshipGameplayAbility.generated.h"

class APlayerSpaceship;
class APlayerSpaceshipController;
class UPlayerShipActionComponent;

UCLASS()
class GMTK25_API UPlayerSpaceshipGameplayAbility : public USpaceshipGameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "Spaceship|Ability")
	APlayerSpaceship* GetPlayerSpaceshipFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Spaceship|Ability")
	APlayerSpaceshipController* GetPlayerSpaceshipControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Spaceship|Ability")
	UPlayerShipActionComponent* GetPlayerShipActionComponentFromActionInfo();
private:
	TWeakObjectPtr<APlayerSpaceship> CachedPlayerSpaceship;
	TWeakObjectPtr<APlayerSpaceshipController> CachedPlayerSpaceshipController;
};

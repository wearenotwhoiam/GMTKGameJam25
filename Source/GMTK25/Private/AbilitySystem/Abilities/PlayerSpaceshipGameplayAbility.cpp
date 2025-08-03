// GMTK Game Jam 2025


#include "AbilitySystem/Abilities/PlayerSpaceshipGameplayAbility.h"
#include "Characters/PlayerSpaceship.h"
#include "Controllers/PlayerSpaceshipController.h"
#include "Components/Action/PawnActionComponent.h"
#include "Components/Action/PlayerShipActionComponent.h"

APlayerSpaceship* UPlayerSpaceshipGameplayAbility::GetPlayerSpaceshipFromActorInfo()
{
    if (!CachedPlayerSpaceship.IsValid())
    {
       CachedPlayerSpaceship = Cast<APlayerSpaceship>(CurrentActorInfo->AvatarActor);
    }
    return CachedPlayerSpaceship.IsValid() ? CachedPlayerSpaceship.Get() : nullptr;
}

APlayerSpaceshipController* UPlayerSpaceshipGameplayAbility::GetPlayerSpaceshipControllerFromActorInfo()
{
    if (!CachedPlayerSpaceshipController.IsValid())
    {
        CachedPlayerSpaceshipController = Cast<APlayerSpaceshipController>(CurrentActorInfo->PlayerController);
    }
    return CachedPlayerSpaceshipController.IsValid() ? CachedPlayerSpaceshipController.Get() : nullptr;
}

UPlayerShipActionComponent* UPlayerSpaceshipGameplayAbility::GetPlayerShipActionComponentFromActionInfo()
{
    return GetPlayerSpaceshipFromActorInfo()->GetPlayerShipActionComponent();
}

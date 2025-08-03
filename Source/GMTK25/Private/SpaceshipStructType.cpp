// GMTK Game Jam 2025


#include "SpaceshipStructType.h"
#include "AbilitySystem/Abilities/SpaceshipGameplayAbility.h"

bool FPlayerShipAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
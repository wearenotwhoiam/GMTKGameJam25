// GMTK Game Jam 2025


#include "Components/Action/PlayerShipActionComponent.h"
#include "Items/Tools/PlayerSpaceshipTool.h"

APlayerSpaceshipTool* UPlayerShipActionComponent::GetPlayerCarriedToolByTag(FGameplayTag InToolTag) const
{
	return Cast<APlayerSpaceshipTool>(GetCharacterCarriedToolByTag(InToolTag));
}

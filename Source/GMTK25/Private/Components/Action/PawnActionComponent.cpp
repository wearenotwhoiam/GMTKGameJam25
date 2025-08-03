// GMTK Game Jam 2025


#include "Components/Action/PawnActionComponent.h"
#include "Components/BoxComponent.h"
#include "Items/Tools/SpaceshipToolBase.h"

#include "DebugHelper.h"

void UPawnActionComponent::RegisterSpawnedTool(FGameplayTag InToolTagToRegister, ASpaceshipToolBase* InToolToRegister, bool bRegisterAsEquippedTool)
{
	checkf(!CharacterCarriedToolMap.Contains(InToolTagToRegister), TEXT("A named %s has already been added as carried tool"), *InToolTagToRegister.ToString());
	check(InToolToRegister);

	CharacterCarriedToolMap.Emplace(InToolTagToRegister, InToolToRegister);

	if (bRegisterAsEquippedTool)
	{
		CurrentEquippedToolTag = InToolTagToRegister;
	}
}

ASpaceshipToolBase* UPawnActionComponent::GetCharacterCarriedToolByTag(FGameplayTag InToolTagToGet) const
{
	if (CharacterCarriedToolMap.Contains(InToolTagToGet))
	{
		if (ASpaceshipToolBase* const* FoundTool = CharacterCarriedToolMap.Find(InToolTagToGet))
		{
			return *FoundTool;
		}
	}
	return nullptr;
}

ASpaceshipToolBase* UPawnActionComponent::GetCharacterCurrentEquippedTool() const
{
	if (!CurrentEquippedToolTag.IsValid())	return nullptr;

	return GetCharacterCarriedToolByTag(CurrentEquippedToolTag);
}

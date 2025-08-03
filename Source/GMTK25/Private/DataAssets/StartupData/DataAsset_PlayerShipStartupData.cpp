// GMTK Game Jam 2025


#include "DataAssets/StartupData/DataAsset_PlayerShipStartupData.h"
#include "AbilitySystem/SpaceshipAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/SpaceshipGameplayAbility.h"

void UDataAsset_PlayerShipStartupData::GiveToAbilitySystemComponent(USpaceshipAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FPlayerShipAbilitySet& AbilitySet : PlayerStartupAbilitySets)
	{
		if (!AbilitySet.IsValid()) return;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
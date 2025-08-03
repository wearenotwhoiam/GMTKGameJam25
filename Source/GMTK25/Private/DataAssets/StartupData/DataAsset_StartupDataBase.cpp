// GMTK Game Jam 2025


#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"
#include "AbilitySystem/SpaceshipAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/SpaceshipGameplayAbility.h"


void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(USpaceshipAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartupDataBase::GrantAbilities(const TArray<TSubclassOf<USpaceshipGameplayAbility>>& InAbilitiesToGive, USpaceshipAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;

	for (const TSubclassOf<USpaceshipGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}

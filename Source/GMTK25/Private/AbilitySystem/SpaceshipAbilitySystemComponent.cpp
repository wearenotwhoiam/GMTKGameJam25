// GMTK Game Jam 2025


#include "AbilitySystem/SpaceshipAbilitySystemComponent.h"

void USpaceshipAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);

	}
}

void USpaceshipAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

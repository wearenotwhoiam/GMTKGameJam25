// GMTK Game Jam 2025


#include "Characters/SpaceshipBasePawn.h"
#include "AbilitySystem/SpaceshipAttributeSet.h"
#include "AbilitySystem/SpaceshipAbilitySystemComponent.h"

// Sets default values
ASpaceshipBasePawn::ASpaceshipBasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	SpaceshipAbilitySystemComponent = CreateDefaultSubobject<USpaceshipAbilitySystemComponent>("SpaceshipAbilitySystemComponent");
	SpaceshipAttributeSet = CreateDefaultSubobject<USpaceshipAttributeSet>("SpaceshipAttributeSet");
}

void ASpaceshipBasePawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (SpaceshipAbilitySystemComponent)
	{
		SpaceshipAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ASpaceshipBasePawn::GetAbilitySystemComponent() const
{
	return GetSpaceshipAbilitySystemComponent();
}
// GMTK Game Jam 2025


#include "Items/Tools/SpaceshipToolBase.h"
#include "Components/BoxComponent.h"

ASpaceshipToolBase::ASpaceshipToolBase()
{
	PrimaryActorTick.bCanEverTick = false;

	ToolMesh = CreateDefaultSubobject<UStaticMeshComponent>("ToolMesh");
	SetRootComponent(ToolMesh);

	ToolCollisionBox = CreateDefaultSubobject<UBoxComponent>("ToolCollisionBox");
	ToolCollisionBox->SetupAttachment(GetRootComponent());
	ToolCollisionBox->SetBoxExtent(FVector(10.f));
	ToolCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

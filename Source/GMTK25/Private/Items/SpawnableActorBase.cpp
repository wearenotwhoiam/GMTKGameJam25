// GMTK Game Jam 2025


#include "Items/SpawnableActorBase.h"

// Sets default values
ASpawnableActorBase::ASpawnableActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnableActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnableActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// GMTK Game Jam 2025



#include "Characters/PlayerSpaceship.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

APlayerSpaceship::APlayerSpaceship()
{
	PrimaryActorTick.bCanEverTick = true;

	//Capsule and Mesh Setup
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(100.f, 100.f);
	CapsuleComponent->SetCollisionProfileName(TEXT("Pawn"));
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);
	BaseMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//Camera Setup
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0, 0, 90);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->AddLocalRotation(FRotator(-90.f, 0.f, 0.f));

	//Input Setup
}

void APlayerSpaceship::BeginPlay()
{
	Super::BeginPlay();
}
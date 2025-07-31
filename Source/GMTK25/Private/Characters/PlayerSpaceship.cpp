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
	CapsuleComponent->InitCapsuleSize(500.f, 500.f);
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);
	BaseMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//Camera Setup
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 2400.f;
	CameraBoom->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
	CameraBoom->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->SetRelativeLocation(FVector(0.f, 0.f, 1250.f));
	FollowCamera->bUsePawnControlRotation = false;
	//Input Setup
}

void APlayerSpaceship::BeginPlay()
{
	Super::BeginPlay();
}
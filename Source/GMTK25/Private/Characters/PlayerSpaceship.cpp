// GMTK Game Jam 2025



#include "Characters/PlayerSpaceship.h"
#include "Components/Input/SpaceshipInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SpaceshipGameplayTags.h"
#include "AbilitySystem/SpaceshipAbilitySystemComponent.h"

#include "DebugHelper.h"

APlayerSpaceship::APlayerSpaceship()
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);

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
	CameraBoom->SetRelativeRotation(FRotator(-57.f, 0.f, 0.f));
	CameraBoom->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
}

void APlayerSpaceship::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	check(LocalPlayer);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	check(Subsystem);
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	USpaceshipInputComponent* SpaceshipInputComponent = CastChecked<USpaceshipInputComponent>(PlayerInputComponent);

	SpaceshipInputComponent->BindNativeInputAction(InputConfigDataAsset, SpaceshipGameplayTags::InputTag_Throttle, ETriggerEvent::Triggered, this, &ThisClass::Input_Throttle);
	SpaceshipInputComponent->BindNativeInputAction(InputConfigDataAsset, SpaceshipGameplayTags::InputTag_Throttle, ETriggerEvent::Completed, this, &ThisClass::Input_Throttle);

	SpaceshipInputComponent->BindNativeInputAction(InputConfigDataAsset, SpaceshipGameplayTags::InputTag_Turn, ETriggerEvent::Triggered, this, &ThisClass::Input_Turn);
}

void APlayerSpaceship::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerSpaceship::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	const FString ASCText = FString::Printf(TEXT("Owner Actor: %s, Avatar Actor: %s"), *SpaceshipAbilitySystemComponent->GetOwnerActor()->GetActorLabel(), *SpaceshipAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
	Debug::Print(ASCText);
}
void APlayerSpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ThrottleValue != 0.f)
	{
		const float CurrentAcceleration = Acceleration * ThrottleValue;
		const float NewForwardSpeed = CurrentForwardSpeed + (CurrentAcceleration * DeltaTime);
		CurrentForwardSpeed = FMath::Clamp(NewForwardSpeed, MinSpeed, MaxSpeed);
		const FVector LocalMove = FVector(CurrentForwardSpeed * DeltaTime, 0.f, 0.f);
		AddActorLocalOffset(LocalMove, true);
	}
	else
	{
		CurrentForwardSpeed = 0.f;
	}
}
void APlayerSpaceship::Input_Throttle(const FInputActionValue& InputActionValue)
{
	ThrottleValue = InputActionValue.Get<float>();
}

void APlayerSpaceship::Input_Turn(const FInputActionValue& InputActionValue)
{
	FVector2D Direction = InputActionValue.Get<FVector2D>();
	if(Direction.Y != 0) AddControllerPitchInput(-Direction.Y);
	if(Direction.X != 0) AddControllerYawInput(Direction.X);
}

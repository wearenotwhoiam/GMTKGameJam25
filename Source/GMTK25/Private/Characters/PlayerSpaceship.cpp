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
#include "Components/Action/PlayerShipActionComponent.h"

#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"
#include "DataAssets/StartupData/DataAsset_PlayerShipStartupData.h"

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

	PlayerShipActionComponent = CreateDefaultSubobject<UPlayerShipActionComponent>(TEXT("PlayerShipActionComponent"));
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

	SpaceshipInputComponent->BindNativeInputAction(InputConfigDataAsset, SpaceshipGameplayTags::InputTag_Strafe, ETriggerEvent::Triggered, this, &ThisClass::Input_Strafe);
	SpaceshipInputComponent->BindNativeInputAction(InputConfigDataAsset, SpaceshipGameplayTags::InputTag_Strafe, ETriggerEvent::Completed, this, &ThisClass::Input_Strafe);

	SpaceshipInputComponent->BindNativeInputAction(InputConfigDataAsset, SpaceshipGameplayTags::InputTag_Roll, ETriggerEvent::Triggered, this, &ThisClass::Input_Roll);
	SpaceshipInputComponent->BindNativeInputAction(InputConfigDataAsset, SpaceshipGameplayTags::InputTag_Roll, ETriggerEvent::Completed, this, &ThisClass::Input_Roll);


	SpaceshipInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void APlayerSpaceship::BeginPlay()
{
	Super::BeginPlay();
	CurrentForwardSpeed = 0;
}

void APlayerSpaceship::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartupData.IsNull())
	{
		if (UDataAsset_StartupDataBase* LoadedData = CharacterStartupData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(SpaceshipAbilitySystemComponent);
		}
	}

}
void APlayerSpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float TargetAcceleration = Acceleration * ThrottleValue;

	if (FMath::IsNearlyZero(ThrottleValue))
	{
		const float DecelerationRate = Acceleration * 0.75f;
		if (CurrentForwardSpeed > 0.f)
		{
			CurrentForwardSpeed -= DecelerationRate * DeltaTime;
			CurrentForwardSpeed = FMath::Max(CurrentForwardSpeed, 0.f);
		}
		else if (CurrentForwardSpeed < 0.f)
		{
			CurrentForwardSpeed += DecelerationRate * DeltaTime;
			CurrentForwardSpeed = FMath::Min(CurrentForwardSpeed, 0.f);
		}
	}
	else
	{
		CurrentForwardSpeed += TargetAcceleration * DeltaTime;

	}

	CurrentForwardSpeed = FMath::Clamp(CurrentForwardSpeed, MinSpeed, MaxSpeed);

	const FVector ForwardMove = FVector(CurrentForwardSpeed * DeltaTime, 0.f, 0.f);
	const FVector StrafeMove = FVector(0.f, StrafeInput.X * StrafeSpeed, StrafeInput.Y * StrafeSpeed);

	AddActorLocalOffset(ForwardMove + StrafeMove, true);

	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Roll = RollInput * RollSpeed * DeltaTime;
	AddActorLocalRotation(FQuat(DeltaRotation));
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

void APlayerSpaceship::Input_Strafe(const FInputActionValue& InputActionValue)
{
	StrafeInput = InputActionValue.Get<FVector2D>();
}

void APlayerSpaceship::Input_Roll(const FInputActionValue& InputActionValue)
{
	RollInput = InputActionValue.Get<float>();
}

void APlayerSpaceship::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	SpaceshipAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void APlayerSpaceship::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	SpaceshipAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
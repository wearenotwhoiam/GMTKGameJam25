// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Characters/SpaceshipBasePawn.h"
#include "GameplayTagContainer.h"
#include "PlayerSpaceship.generated.h"


class UCameraComponent;
class USpringArmComponent;
class UCapsuleComponent;
class UDataAsset_InputConfig;
class UPlayerShipActionComponent;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class GMTK25_API APlayerSpaceship : public ASpaceshipBasePawn
{
	GENERATED_BODY()
public:
	APlayerSpaceship();
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.

private:
#pragma region Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Actions", meta = (AllowPrivateAccess = "true"))
	UPlayerShipActionComponent* PlayerShipActionComponent;
#pragma endregion	

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Throttle(const FInputActionValue& InputActionValue);
	void Input_Turn(const FInputActionValue& InputActionValue);
	void Input_Strafe(const FInputActionValue& InputActionValue);
	void Input_Roll(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
#pragma endregion

#pragma region Movement
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Acceleration = 2000.f;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MaxSpeed = 6000.f;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MinSpeed = -3000.f;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float StrafeSpeed = 2000.f;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float RollSpeed = 80.f;

	float CurrentForwardSpeed = 0.f;
	float ThrottleValue = 0.f;
	FVector2D StrafeInput = FVector2D::ZeroVector; 
	float RollInput = 0.f;
#pragma endregion

public:
	FORCEINLINE UPlayerShipActionComponent* GetPlayerShipActionComponent() const { return PlayerShipActionComponent; }
};

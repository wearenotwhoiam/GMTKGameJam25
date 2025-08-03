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

	APlayerController* PlayerController;

	void Input_Throttle(const FInputActionValue& InputActionValue);
	void Input_Turn(const FInputActionValue& InputActionValue);
	void Input_Strafe(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
#pragma endregion

#pragma region Movement
	float ThrottleValue{ 0.f };
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MovementSettings", meta = (AllowPrivateAccess = "true"))
	float Acceleration{ 100.f };
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MovementSettings", meta = (AllowPrivateAccess = "true"))
	float MaxSpeed{ 10000.f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovementSettings", meta = (AllowPrivateAccess = "true"))
	float MinSpeed = -MaxSpeed;

	float CurrentForwardSpeed = 0;
#pragma endregion
public:
	FORCEINLINE UPlayerShipActionComponent* GetPlayerShipActionComponent() const { return PlayerShipActionComponent; }
};

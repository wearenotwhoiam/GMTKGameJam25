// GMTK Game Jam 2025

#pragma once

#include "CoreMinimal.h"
#include "Characters/SpaceshipBasePawn.h"
#include "PlayerSpaceship.generated.h"


class UCameraComponent;
class USpringArmComponent;
class UCapsuleComponent;
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
	virtual void BeginPlay() override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
#pragma endregion	
};

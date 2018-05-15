// Trespassers will be shot!

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "AITankController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AAITankController : public AAIController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

private:

	ATank* getControlledTank() const;
	APlayerController* findPlayerController() const;

	ATank* controlledTank = nullptr;
	ATank* playerTank = nullptr;

	void targetPlayer(ATank* player);
	
	/*  Aiming:
		Find player and store the instance tank player is using
		Get location of player tank
		Calculate aim projectile physics to hit player tank
		Move canon
		Fire
	*/
};


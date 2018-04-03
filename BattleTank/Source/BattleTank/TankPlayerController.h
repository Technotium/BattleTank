// Trespassers will be shot!

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATank* getControlledTank() const;
	
	virtual void BeginPlay() override;
	
	ATank* myTank = nullptr;
	
};

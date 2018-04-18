// Trespassers will be shot!

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Components/Widget.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATankPlayerController(); 

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	ATank* getControlledTank() const;

	// Get the screenspace location of the crosshair to know where on the screen to trace from
	FVector2D findCrosshairScreenSpace() const;

	// Convert the screenspace location of the crosshair to worldspace so that we can trace from the world location
	FVector convertSSToWS(FVector2D screenSpaceCrosshair) const;

	// Trace from crosshair world location to what lies beneath the crosshair
	FHitResult traceFromCrosshair(FVector worldSpaceCrosshair) const;

	// Get the place in the world that the crosshair is over
	FVector getAimWorldLocation(FHitResult traceResult) const;

	// Rotate the cannon to the crosshair
	void aimToCrosshair(FVector locationUnderCrosshair);
	
	ATank* myTank = nullptr;
	
};

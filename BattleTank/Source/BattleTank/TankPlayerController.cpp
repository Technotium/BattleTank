// Trespassers will be shot!


#include "TankPlayerController.h"

ATankPlayerController::ATankPlayerController() {

	PrimaryActorTick.bCanEverTick = true;
}


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	myTank = getControlledTank();
	if (!myTank) { UE_LOG(LogTemp, Warning, TEXT("No tank associated with TankPlayerController")); return; }

	//UE_LOG(LogTemp, Display, TEXT("%s found by TankPlayerController!"), *myTank->GetName());
};


void ATankPlayerController::Tick(float DeltaTime) {
	
	// Tick
	Super::Tick(DeltaTime);
		// AimTowardsCrossHair
}


ATank* ATankPlayerController::getControlledTank() const { return Cast<ATank>(GetPawn()); }


FVector2D ATankPlayerController::findCrosshairScreenSpace() const
{
	if (!myTank) { return; }
	return;
}

FVector ATankPlayerController::convertSSToWS(FVector2D screenSpaceCrosshair) const
{

	return;
}


FHitResult ATankPlayerController::traceFromCrosshair(FVector worldSpaceCrosshair) const {
	return;
}

FVector ATankPlayerController::getAimWorldLocation(FHitResult traceResult) const
{
	return;
}

void ATankPlayerController::aimToCrosshair(FVector locationUnderCrosshair)
{
	if (!myTank) { return; }
}

// Trespassers will be shot!


#include "TankPlayerController.h"



ATank* ATankPlayerController::getControlledTank() const { return Cast<ATank>(GetPawn()); }

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	myTank = getControlledTank();
	if (!myTank) { UE_LOG(LogTemp, Warning, TEXT("No tank associated with TankPlayerController")); return; }

	//UE_LOG(LogTemp, Display, TEXT("%s found by TankPlayerController!"), *myTank->GetName());
};

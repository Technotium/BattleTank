// Trespassers will be shot!


#include "TankPlayerController.h"

ATank * ATankPlayerController::getControlledTank() const { return Cast<ATank>(GetPawn()); }


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
	aimToCrosshair({ 0,0,0 });
}


void ATankPlayerController::aimToCrosshair(FVector locationUnderCrosshair) {
	if (!getControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("No tank associated with TankPlayerController"));
		return;
	}

	FVector2D SSCoords = findCrosshairScreenSpace();
	FVector WSCoords;
	FVector lookTranslation;
	FRotator lookRotation;

	GetPlayerViewPoint(OUT lookTranslation, OUT lookRotation);

	if (traceFromCrosshair(reach, lookTranslation, lookRotation, OUT WSCoords)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *WSCoords.ToString());
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("HitLocation: Nothing"));
	return;
};

FVector2D ATankPlayerController::findCrosshairScreenSpace() const
{
	return { 0,0 };
}


// Traces from crosshair to whatever is underneath it, returns true if it hits
bool ATankPlayerController::traceFromCrosshair(float reach, FVector translation, FRotator rotation, FVector& OutHitLocation) const
{

	FHitResult lineTraceHit;
	FCollisionQueryParams traceParameters(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByChannel(
		lineTraceHit,
		translation,
		rotation.Vector() * reach + translation,
		ECollisionChannel::ECC_WorldStatic,
		traceParameters

	);

	DrawDebugLine(
		GetWorld(),
		translation,
		rotation.Vector() * reach + translation,
		{ 255,127,127 },
		true,
		0.5f,
		000,
		0.05f

	);

	DrawDebugBox(
		GetWorld(),
		lineTraceHit.Location,
		{ 100.f, 100.f, 100.f },
		{ 255, 127, 127 },
		true,
		0.5f,
		000,
		1.f


		);

	OutHitLocation = lineTraceHit.Location;

	


	return lineTraceHit.bBlockingHit;

}

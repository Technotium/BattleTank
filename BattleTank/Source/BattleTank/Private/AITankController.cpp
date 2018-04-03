// Trespassers will be shot!

#include "AITankController.h"


ATank* AAITankController::getControlledTank() const { return Cast<ATank>(GetPawn()); }

void AAITankController::BeginPlay() {
	Super::BeginPlay();

	controlledTank = getControlledTank();
	if (!controlledTank) { UE_LOG(LogTemp, Warning, TEXT("No tank associated with TankAIController")) return; }

	//UE_LOG(LogTemp, Display, TEXT("%s found by TankAIController!"), *controlledTank->GetName());

	playerTank = Cast<ATank>(findPlayerController()->GetPawn());
	if (! playerTank) { UE_LOG(LogTemp, Warning, TEXT("No playercontroller associated with world")) return; }
	
	//UE_LOG(LogTemp, Display, TEXT("%s found as playerTank"), *playerTank->GetName())

	
};


APlayerController* AAITankController::findPlayerController() const {
	return (GetWorld()->GetFirstPlayerController());
};


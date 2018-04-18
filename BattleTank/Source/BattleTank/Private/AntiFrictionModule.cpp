// Trespassers will be shot!

#include "AntiFrictionModule.h"


// Sets default values for this component's properties
UAntiFrictionModule::UAntiFrictionModule()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAntiFrictionModule::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAntiFrictionModule::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


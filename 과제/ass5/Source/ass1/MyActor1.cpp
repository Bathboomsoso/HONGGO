// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();

	Move();
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

double AMyActor1::Step()
{
	return FMath::RandBool() ? 1.0 : 0.0;
}

void AMyActor1::Move()
{
	FVector Location = FVector::ZeroVector;
	UE_LOG(LogTemp, Warning, TEXT("Location : (%.2f, %.2f))"), Location.X, Location.Y);

	for (int32 i = 0; i < 10; ++i)
	{
		Location += FVector(Step(), Step(), 0);
		UE_LOG(LogTemp, Warning, TEXT("Location : (% .2f, % .2f)"), Location.X, Location.Y);
	}
}

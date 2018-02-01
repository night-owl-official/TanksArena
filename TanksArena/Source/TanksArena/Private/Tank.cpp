// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

#include "Engine/World.h"
#include "Components/SceneComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Make the aiming component at construction time
	_tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector hitPosition) const {
	// Delegate aiming to dedicated component
	_tankAimingComponent->AimAt(hitPosition, _launchSpeed);
}

void ATank::Fire() const {
	// Get out if there is no barrel
	if (!_barrel || !_projectile)
		return;

	// Spawn a projectile at the barrel's socket location and rotation
	FVector outProjectileSpawnLocation =
		_barrel->GetSocketLocation(FName(UTankAimingComponent::PROJECTILE_SPAWN_SOCKET));
	FRotator outProjectileSpawnRotation =
		_barrel->GetSocketRotation(FName(UTankAimingComponent::PROJECTILE_SPAWN_SOCKET));
	
	AActor* newProjectile = 
		GetWorld()->SpawnActor<AProjectile>(_projectile,
			outProjectileSpawnLocation,
			outProjectileSpawnRotation);
}

void ATank::SetBarrel(UTankBarrel* barrel) {
	// Delegate it to the aiming component
	_tankAimingComponent->SetBarrel(barrel);

	// Keep a local reference of it too
	_barrel = barrel;
}

void ATank::SetTurret(UTankTurret* turret) const {
	// Delegate it to the aiming component
	_tankAimingComponent->SetTurret(turret);
}

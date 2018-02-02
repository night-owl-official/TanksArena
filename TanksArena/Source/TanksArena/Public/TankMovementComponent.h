// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class UTankTrack;

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * Gives control over the movement of the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKSARENA_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	/** Initializes the left and right tracks
	* @param Left track to set
	* @param Right track to set
	*/
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankTrack* leftTrack, UTankTrack* rightTrack);

	/** Sets up the tank to move forward and backwards
	* @param How far forward or backwards the tank will move
	*/
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float theThrow) const;

	/** Sets up the tank to move right and left
	* @param How far right or left the tank will move
	*/
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float theThrow) const;

private:
	UTankTrack* _leftTrack = nullptr;	// Reference to the tank's left track
	UTankTrack* _rightTrack = nullptr;	// Reference to the tank's right track
};

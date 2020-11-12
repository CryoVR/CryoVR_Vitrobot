// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019
#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_AirTankActor.generated.h"

/**
 * 
 */

class UStaticMeshComponent;
class UCapsuleComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_AirTankActor : public AVB_StaticActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* firstKnob;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* secondKnob;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* firstPointer;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* secondPointer;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UCapsuleComponent* secondKnobCollisionComp;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
		bool m_isSecondKnobOn;

public:
	bool m_isFirstKnobOn;



	AVB_AirTankActor();

	virtual void Tick(float DeltaTime) override;

	FRotator tempA;
	FRotator tempB;
	
};

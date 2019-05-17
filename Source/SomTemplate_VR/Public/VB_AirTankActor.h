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
private:
	bool m_isFirstKnobOn;
protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* firstKnob;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* secondKnob;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* firstPointer;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* secondPointer;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UCapsuleComponent* secondKnobCollisionComp;

public:
	AVB_AirTankActor();

	virtual void Tick(float DeltaTime) override;
	
};

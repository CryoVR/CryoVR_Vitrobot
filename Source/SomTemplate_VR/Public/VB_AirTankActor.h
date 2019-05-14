// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_AirTankActor.generated.h"

/**
 * 
 */

class UStaticMeshComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_AirTankActor : public AVB_StaticActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* firstKnob;

	

public:
	AVB_AirTankActor();

	virtual void Tick(float DeltaTime) override;
	
};

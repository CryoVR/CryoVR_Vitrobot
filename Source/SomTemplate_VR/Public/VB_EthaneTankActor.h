// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019
#pragma once

#include "CoreMinimal.h"
#include "VB_AirTankActor.h"
#include "VB_EthaneTankActor.generated.h"

/**
 * 
 */
class UCapsuleComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_EthaneTankActor : public AVB_AirTankActor
{
	GENERATED_BODY()
public:
	AVB_EthaneTankActor();
	//Get Component by index
	virtual USceneComponent* GetComponentByIndex(int indexComp = 0);

protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UCapsuleComponent* ethaneTipPosCollisionComp;

};

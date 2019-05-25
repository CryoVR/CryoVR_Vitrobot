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

class AVB_EthaneTipActor;

UCLASS()
class SOMTEMPLATE_VR_API AVB_EthaneTankActor : public AVB_AirTankActor
{
	GENERATED_BODY()
public:
	AVB_EthaneTankActor();
	//Get Component by index
	virtual USceneComponent* GetComponentByIndex(int indexComp = 0);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnTipOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnyWhere, Category = "Particles")
		UParticleSystemComponent* particle;
	


protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UCapsuleComponent* ethaneTipPosCollisionComp;

	AVB_EthaneTipActor* ethaneTip;
};

// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019
#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_EthaneTipActor.generated.h"

/**
 * 
 */

class UParticleSystem;
class UCapsuleComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_EthaneTipActor : public AVB_DynamicActor
{
	GENERATED_BODY()
	
public:
	AVB_EthaneTipActor();

protected:
	UPROPERTY(VisibleAnyWhere, Category = "Particles")
		UParticleSystem* ethaneParticle;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCapsuleComponent* ethaneTipCollisionComp;

	UFUNCTION()
	void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};

// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_FreezingDewarActor.generated.h"

/**
 * 
 */

class UCapsuleComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_FreezingDewarActor : public AVB_StaticActor
{
	GENERATED_BODY()

public:
	AVB_FreezingDewarActor();

	UFUNCTION()
		void OnDewarOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UCapsuleComponent* capsuleComp;

	UPROPERTY(VisibleAnywhere, Category = "Particles")
		UParticleSystemComponent* P_Frozen;
	
};

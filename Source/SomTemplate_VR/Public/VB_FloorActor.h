// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019
#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_FloorActor.generated.h"

class AVB_DynamicActor;
/**
 * This class represents floor. This class will be responsible for teleporting dynamic actors back to their original location when dynamic actors collide with the floor.
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_FloorActor : public AVB_StaticActor
{
	GENERATED_BODY()
public:
	AVB_FloorActor();

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Timer")
	float teleportDynamicActorTimer;

protected:
	
};

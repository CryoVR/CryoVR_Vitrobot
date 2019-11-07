// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_SideCoverActor.generated.h"

/**
 * 
 */

class UStaticMeshComponent;


UCLASS()
class SOMTEMPLATE_VR_API AVB_SideCoverActor : public AVB_StaticActor
{
	GENERATED_BODY()
public:
	AVB_SideCoverActor();

	void setcoverVisible();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	FTimerHandle UnusedHandle;

	bool isCoverTouched;
};

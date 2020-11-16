// Copyright (c) 2017-2020 CryoVR, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_CleanLiquidSampleRack.generated.h"

/**
 * 
 */

class UBoxComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_CleanLiquidSampleRack : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	AVB_CleanLiquidSampleRack();

	UPROPERTY(BlueprintReadWrite)
		bool bIsOnTable;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnHandOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UBoxComponent* boxComp;
	
};

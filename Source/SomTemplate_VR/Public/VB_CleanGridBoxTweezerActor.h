// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_CleanGridBoxTweezerActor.generated.h"

/**
 * 
 */
class UStaticMeshComponent;
class UCapsuleComponent;


UCLASS()
class SOMTEMPLATE_VR_API AVB_CleanGridBoxTweezerActor : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	AVB_CleanGridBoxTweezerActor();

	UPROPERTY(BlueprintReadWrite)
	bool bIsOnTable;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

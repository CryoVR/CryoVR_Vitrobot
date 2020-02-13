// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_GloveActor.generated.h"

class UBoxComponent;
/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_GloveActor : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	AVB_GloveActor();

	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		bool Is_Weard_Gloves;

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* BoxComp;

};

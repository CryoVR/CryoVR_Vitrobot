// Copyright (c) 2017-2020 CryoVR, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_Assemble_Workstation_Main.generated.h"

/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_Assemble_Workstation_Main : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	AVB_Assemble_Workstation_Main();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};

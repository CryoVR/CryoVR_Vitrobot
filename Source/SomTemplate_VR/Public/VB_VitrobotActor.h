// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_VitrobotActor.generated.h"

class UBoxComponent;
/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_VitrobotActor : public AVB_StaticActor
{
	GENERATED_BODY()

public:
	AVB_VitrobotActor();


protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* WorkstationHolder;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* InnerHolder;
	
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* BottomCover;
	
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* LEDCover;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* WorkstationHolder_Collider;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BottomCover_Collider;
};

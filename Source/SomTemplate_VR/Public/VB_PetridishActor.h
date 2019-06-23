// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_PetridishActor.generated.h"

/**
 * 
 */
class UCapsuleComponent;
class UBoxComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_PetridishActor : public AVB_StaticActor
{
	GENERATED_BODY()
	
public:
	AVB_PetridishActor();

	//return the grid
	UStaticMeshComponent* GetGrid();


protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* petridish_grid;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UBoxComponent* boxComp;
};

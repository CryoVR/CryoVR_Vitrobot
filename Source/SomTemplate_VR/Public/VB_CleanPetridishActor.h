// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_CleanPetridishActor.generated.h"

/**
 * 
 */
class UBoxComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_CleanPetridishActor : public AVB_DynamicActor
{
	GENERATED_BODY()
		
public:
	AVB_CleanPetridishActor();

	UPROPERTY(BlueprintReadWrite)
	bool bISCleanPetridishOnTable;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
protected:

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UBoxComponent* boxComp;
	
};

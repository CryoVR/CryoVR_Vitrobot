// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_PipetteActor.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_PipetteActor : public AVB_DynamicActor
{
	GENERATED_BODY()

public:

	//Set default
	AVB_PipetteActor();
	//Declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//This is the function that may be used in the future
	//UFUNCTION()
	//void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);
protected:

		UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* SphereComp;
		UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* OverlappedComp;
		AActor* OverlappedActor;
		UMaterialInstance* TempMaterial;


};

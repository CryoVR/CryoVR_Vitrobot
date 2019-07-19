// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_WorkstationActor.generated.h"

class UBoxComponent;
class UCapsuleComponent;
/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_WorkstationActor : public AVB_DynamicActor
{
	GENERATED_BODY()

public:

	void setFrozVisible();

	//Set as default
	AVB_WorkstationActor();

	//Declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/*UFUNCTION()
		void OnTipOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/

	

	
	
protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, Category = "Particles")
	UParticleSystemComponent* FrozenFX;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Workstation_P0;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Workstation_P1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Workstation_P2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Water_Mesh;

private:
	bool bIsAttached;

	//check is ethane tip added
	bool isEthaneAdded;

	FTimerHandle UnusedHandle;

	int Status;
	FVector DeltaLocation;
	FVector TempLocation;
};

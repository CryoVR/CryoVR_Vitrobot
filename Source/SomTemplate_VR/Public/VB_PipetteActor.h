// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_PipetteActor.generated.h"

class USphereComponent;
class UCapsuleComponent;

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
	//Hand gesture setting
	UFUNCTION()
	void OnPipetHandOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* OverlappedComp;
	AActor* OverlappedActor;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCapsuleComponent* HandcapsuleComp;

	UPROPERTY(EditAnywhere, Category = "Material")
	class UMaterial* OnMaterial;

	UPROPERTY(EditAnywhere, Category = "Material")
	class UMaterial* OffMaterial;

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;
};

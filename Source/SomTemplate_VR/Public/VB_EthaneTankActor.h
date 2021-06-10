 // Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019
#pragma once

#include "CoreMinimal.h"
#include "VB_AirTankActor.h"
#include "VirtualReality/TP_InteractionInterface.h"
#include "VB_EthaneTankActor.generated.h"

/**
 * 
 */
class UCapsuleComponent;
class UAudioComponent;
class AVB_EthaneTipActor;

UCLASS()
class SOMTEMPLATE_VR_API AVB_EthaneTankActor : public AVB_AirTankActor, public ITP_InteractionInterface
{
	GENERATED_BODY()
public:
	AVB_EthaneTankActor();
	//Get Component by index
	virtual USceneComponent* GetComponentByIndex(int indexComp = 0);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnTipOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnyWhere, Category = "Particles")
		UParticleSystemComponent* particle;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
		bool Is_Second_Open;

	virtual void Pickup_Implementation(class USceneComponent* AttachTo);

	virtual void Drop_Implementation();

	bool m_isTipOn;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
		bool bp_firstknobOn;
	

protected:
	USceneComponent * handObjRef;

	AVB_EthaneTipActor* ethaneTip;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UCapsuleComponent* ethaneTipPosCollisionComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* Hissing_Sound;

	float m_HandInitialKnobDeltaRotator;

	bool bIsFirstKnobTouched;

	bool bIsFirstKnobHold;

	bool bIsSecondKnobTouched;

	bool bIsSecondKnobHold;

	



	//virtual void Tick(float DeltaTime) override;

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;


};

// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_DewarActor.generated.h"

/**
 * 
 */

class UParticleSystemComponent;
class UBoxComponent;
class UCapsuleComponent;


UCLASS()
class SOMTEMPLATE_VR_API AVB_DewarActor : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	//Set as default
	AVB_DewarActor();

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* BoxCompCap;

	//Declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Hand gesture setting
	UFUNCTION()
		void OnHandOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	virtual void Tick(float DeltaTime) override;

protected:

	
	UPROPERTY(VisibleAnywhere, Category = "ParticleEffect")
		UParticleSystemComponent* FrozenFX;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCapsuleComponent* HandcapsuleComp;

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;

private:
	bool m_IsFirstTimeTouch = true;
	bool m_IsSecondTimeTouch = false;

};

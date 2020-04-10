// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_NitrogenTankCapActor.generated.h"

class UCapsuleComponent;

/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_NitrogenTankCapActor : public AVB_DynamicActor
{
	GENERATED_BODY()
	
public:
	AVB_NitrogenTankCapActor();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void Tick(float DeltaTime) override;

	virtual void ResetActorState() override;

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCapsuleComponent* CapsuleComp;

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;
	

	

};


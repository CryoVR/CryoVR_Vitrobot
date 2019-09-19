// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_GridBoxTweezerActor.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_GridBoxTweezerActor : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	AVB_GridBoxTweezerActor();

	bool m_isGridAttached;

	bool m_isTweezerFrozen;

	bool m_isTweezerGridShow;

	

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnPointerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* tweezer_grid;

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCapsuleComponent* capsuleComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCapsuleComponent* tweezerMainCapsuleComp;

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;

};

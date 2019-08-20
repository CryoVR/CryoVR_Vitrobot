// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_GridDewarActor.generated.h"

class UBoxComponent;
/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_GridDewarActor : public AVB_StaticActor
{
	GENERATED_BODY()

	AVB_GridDewarActor();

public:
	/*UFUNCTION()
	void OnCapOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	*/
	UFUNCTION()
		void SetIsTouchable(bool B);

	UFUNCTION()
		bool GetIsTouchable();
	
protected:

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* GridDewarCap;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UBoxComponent* GridDewarCap_Collider;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UBoxComponent* GridDewar_Collider;

private:
	bool IsTouchable;
};

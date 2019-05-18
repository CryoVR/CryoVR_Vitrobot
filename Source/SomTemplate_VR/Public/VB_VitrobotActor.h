// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_VitrobotActor.generated.h"

class UBoxComponent;
/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_VitrobotActor : public AVB_StaticActor
{
	GENERATED_BODY()

public:
	AVB_VitrobotActor();

	UFUNCTION()
	void ActiveInnerHolder(bool bIs);

	UFUNCTION()
	void DeactiveInnerHolder(bool bIs);

	UFUNCTION()
	void SetInteractableByRotation(UStaticMeshComponent* SM_Mesh);

	UFUNCTION()
	void MoveWorkstationHolder(float F);

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* WorkstationHolder;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* InnerHolder;
	
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* BottomCover;
	
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* LEDCover;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* WorkstationHolder_Collider;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BottomCover_Collider;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* TestButton_Collider;

private:
	bool bIsInteractable;
	bool bIsButtonOn;
	bool bIsHolderGoingUp;
};

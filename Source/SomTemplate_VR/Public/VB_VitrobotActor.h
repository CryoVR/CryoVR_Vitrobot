// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_VitrobotActor.generated.h"

class UBoxComponent;
class UAudioComponent;
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
	void SetInteractableByRotation(UStaticMeshComponent* SM_Mesh);

	UFUNCTION()
	void MoveWorkstationHolder(float F);

	UPROPERTY(BlueprintReadwrite, Category = "Components")
	UStaticMeshComponent* WorkstationHolder;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* Door;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UBoxComponent* Plunger_Collider;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* Plunger;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UBoxComponent* TestButton_Collider;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UBoxComponent* Pen_Collider;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UBoxComponent* PowerButton_Collider;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* PlungerSound;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* Holder_Sound;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* Blotter_Sound;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* Button_Sound;


	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void TurnOnMachine(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void TouchScreen(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



	UFUNCTION()
	void PlungerDelay();

	virtual void Tick(float DeltaTime) override;



protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Screen;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* InnerHolder;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* InnerHolder_LeftU;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* InnerHolder_RightU;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* InnerHolder_LeftD;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* InnerHolder_RightD;
	
	//UPROPERTY(VisibleAnyWhere, Category = "Components")
	//UStaticMeshComponent* Door;
	
	/*UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* LEDCover;*/
	

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* Bottom_Cover;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UBoxComponent* WorkstationHolder_Collider;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* Door_Collider;



	UPROPERTY(EditAnywhere, Category = "Components")
	class UMaterial* MainMaterial;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UMaterial* OptionMaterial;

	UMaterialInstanceDynamic* DynamicMaterialInst;

	UPROPERTY(EditAnywhere)
	AActor* ACT;

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;


private:
	bool m_IsMachineOn = false;
	bool bIsInteractable;
	bool bIsButtonOn;
	bool bIsHolderGoingUp;
	bool bIsHolderTouchingBottom;
	bool bIsHolderMovingFoward;
	bool bPlungerStatus;
	bool bIsDoorOn;
	bool bIsDoorGoingOpen;
	bool bIsZooming;

	int LevelStatus = 0;
	int Status = 1;
	int Counter = 0;
	int ZoomingTime = 0;
	int ZoomingDirection = 1;
};

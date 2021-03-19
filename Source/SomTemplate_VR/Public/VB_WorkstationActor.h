// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_WorkstationActor.generated.h"

class UBoxComponent;
class UCapsuleComponent;
class UParticleSystemComponent;
class UAudioComponent;
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

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Workstation_P3;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Workstation_P2;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UBoxComponent* BoxComp;


	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Workstation_P0;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Workstation_P1;

	//Declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnGridBoxOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		float GetEthaneProgress();

	virtual void Tick(float DeltaTime) override;

	/*UFUNCTION()
		void OnTipOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		bool is_OnTable;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		bool is_PutBack;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		float Ethane_Progress;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		bool Is_EthaneAdding;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		bool Is_CoolingDown;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		float CoolDownTime;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Water_Mesh;

protected:



	UPROPERTY(VisibleAnywhere, Category = "Particles")
		UParticleSystemComponent* FrozenFX;






	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;


private:
	bool bIsAttached;

	bool isTipTouched;

	//check is ethane tip added
	bool isEthaneAdded;

	FTimerHandle UnusedHandle;

	int Status;
	FVector DeltaLocation;
	FVector TempLocation;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* PouringSound;

};

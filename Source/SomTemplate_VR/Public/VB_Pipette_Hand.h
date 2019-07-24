// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_Pipette_Hand.generated.h"

class UWidgetComponent;
class USkeletalMeshComponent;

/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_Pipette_Hand : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	AVB_Pipette_Hand();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float PressureValue = 0.0;

	virtual void Tick(float DeltaTime) override;

private:
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	//TSubclassOf<class UUserWidget> NameplateUIClass;

	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = UI)
	//class UUserWidget* NameplateWidget;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* MeshComp;


	
};

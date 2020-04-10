// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_StaticActor.h"
#include "VB_LabCoatActor.generated.h"

/**
 * 
 */
class UBoxComponent;
UCLASS()
class SOMTEMPLATE_VR_API AVB_LabCoatActor : public AVB_StaticActor
{
	GENERATED_BODY()

public:
	AVB_LabCoatActor();
		
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(BlueprintReadWrite, Category = "Components")
		bool Is_Weard_Coat;

protected:
		
	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;
		
};


// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VB_DynamicActor.h"
#include "VB_PetridishCoverActor.generated.h"

class UBoxComponent;


UCLASS()
class SOMTEMPLATE_VR_API AVB_PetridishCoverActor : public AVB_DynamicActor
{
	GENERATED_BODY()

public:
	AVB_PetridishCoverActor();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnHandOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent * covercollisionComp;

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;
	
};

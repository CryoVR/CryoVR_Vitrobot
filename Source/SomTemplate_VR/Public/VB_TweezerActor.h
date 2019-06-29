// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VB_DynamicActor.h"
#include "VB_TweezerActor.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;


UCLASS()
class SOMTEMPLATE_VR_API AVB_TweezerActor : public AVB_DynamicActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVB_TweezerActor();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnTweezerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* tweezer_grid;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCapsuleComponent* capsuleComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCapsuleComponent* tweezerMainCapsuleComp;

};

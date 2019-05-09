// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VB_StaticActor.generated.h"

class UStaticMeshComponent;
class UShapeComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_StaticActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVB_StaticActor();
	

protected:
	//Member Variables
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* meshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UShapeComponent* shapeComp;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

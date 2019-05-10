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

	//Indicate whether the device is on or off, by default it's off
	bool m_isOn;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Return whether the device is on or off
	virtual bool getState();
	//Set the device state.
	virtual void setState(bool newState);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

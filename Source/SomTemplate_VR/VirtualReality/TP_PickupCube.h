// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
// SomWorks :D // MIT LICENSE // Epic VR Template Convert C++ Open Source Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP_InteractionInterface.h"
#include "TP_PickupCube.generated.h"

class ATP_MotionController;

UCLASS()
class SOMTEMPLATE_VR_API ATP_PickupCube : public AActor, public ITP_InteractionInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VRTemplate|Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

	
protected:
	
	//All the following variables are responsible for handling hand guesture update, will be updated by UpdateHandGuestureFunc in derived class 
	//Determines whether we need to use our customized hand gesture, if not, default bahavior will used
	bool m_isDefinedPick;
	//Save the object's socket name which this object is going to attach
	FName m_attachSocketName;
	//Set up attachment rule : keep world, keep relative and snap to target
	EAttachmentRule m_attachToSocketRule;
	//Set up the orginal dynamic object scale
	FVector m_originalScale3D;

	//Saved motioncontroller pointer
	ATP_MotionController* m_ourMotionController;

public:	
	// Sets default values for this actor's properties
	ATP_PickupCube();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateHandGuestureFunc(bool isDefinedPick, const FName & attachSocketName, const EAttachmentRule & attachToSocketRule, const FVector & V, const TArray<float>& handGuesture, ATP_MotionController* motionController);

	void ResetHandGuestureFunc();
	
	virtual void Pickup_Implementation(class USceneComponent* AttachTo);
		
	virtual void Drop_Implementation();

};

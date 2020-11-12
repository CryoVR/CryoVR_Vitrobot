// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
// SomWorks :D // MIT LICENSE // Epic VR Template Convert C++ Open Source Project.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TP_Variables.h"
#include "TP_HandAnimInstance.generated.h"

UCLASS()
class SOMTEMPLATE_VR_API UTP_HandAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	UTP_HandAnimInstance();
	
public:
	UFUNCTION(BlueprintCallable, Category = "VRTemplate|Teleportation")
	void SetGripState(EGrip_Code GripState, const TArray<float>& HandGestureInput);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	EGrip_Code CurrentGripState;
	//Defines the animation state, currently we only have 2 axis. 
	//Accept values from TP_MotionController/HandGesturetoAnimationBP
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	TArray<float> HandGuestureParameters;


protected:
	
public:
	
};

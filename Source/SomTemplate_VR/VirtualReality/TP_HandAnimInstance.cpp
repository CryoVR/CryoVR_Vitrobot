// Copyright (c) 2014-2018 Sombusta, All Rights Reserved.
// SomWorks :D // MIT LICENSE // Epic VR Template Convert C++ Open Source Project.

#include "TP_HandAnimInstance.h"

UTP_HandAnimInstance::UTP_HandAnimInstance()
{
	CurrentGripState = EGrip_Code::Open;
	//Default state of our hand
	HandGuestureParameters = { 0.0, 1.0 };
}

void UTP_HandAnimInstance::SetGripState(EGrip_Code GripState, const TArray<float>& HandGestureInput)
{
	CurrentGripState = GripState;
	if (HandGestureInput.Num() == 2) {
		HandGuestureParameters[0] = HandGestureInput[0];
		HandGuestureParameters[1] = HandGestureInput[1];
	}
	else {
		HandGuestureParameters = { 0.0, 1.0 };
	}
}

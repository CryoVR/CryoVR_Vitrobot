// Copyright (c) 2017-2020 CryoVR, All Rights Reserved.


#include "VB_Assemble_Workstation_P0.h"
#include "VB_Assemble_Workstation_Main.h"
#include "VB_CleanTweezerActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VB_PetridishActor.h"
#include "VB_PetridishCoverActor.h"
#include "VB_StaticActor.h"
#include "VB_WorkstationActor.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_LevelScriptActor.h"
#include "VB_VitrobotActor.h"
#include "VB_CleanTableCompActor.h"

AVB_Assemble_Workstation_P0::AVB_Assemble_Workstation_P0()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanTweezer(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/vitrobot_m_WorkStation_P0.vitrobot_m_WorkStation_P0'"));
	if (SM_CleanTweezer.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_CleanTweezer.Object);
	}
	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_Assemble_Workstation_P0::OnOverlapBegin);

}

void AVB_Assemble_Workstation_P0::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("Tweezer_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.0f, 0.5f}, Cast<ATP_MotionController>(OtherActor));
	}

}


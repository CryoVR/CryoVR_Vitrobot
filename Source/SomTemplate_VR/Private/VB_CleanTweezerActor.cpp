// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


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

AVB_CleanTweezerActor::AVB_CleanTweezerActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanTweezer(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Tweezer.Tweezer'"));
	if (SM_CleanTweezer.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_CleanTweezer.Object);
	}
	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanTweezerActor::OnOverlapBegin);
}

void AVB_CleanTweezerActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bIsOnTable = true;
		
	}
}

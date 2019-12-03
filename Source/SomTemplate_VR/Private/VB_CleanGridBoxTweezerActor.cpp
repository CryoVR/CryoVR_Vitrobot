// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanGridBoxTweezerActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VB_WorkstationActor.h"
#include "VB_GridTubeActor.h"
#include "VB_FreezingDewarActor.h"
#include "VB_StaticActor.h"
#include "VB_LevelScriptActor.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_VitrobotActor.h"
#include "VB_CleanTableCompActor.h"

AVB_CleanGridBoxTweezerActor::AVB_CleanGridBoxTweezerActor()
{
	bIsOnTable = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanGridTweezer(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Tweezer.Tweezer'"));
	if (SM_CleanGridTweezer.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_CleanGridTweezer.Object);
	}
	PickupMesh->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanGridBoxTweezerActor::OnOverlapBegin);

}

void AVB_CleanGridBoxTweezerActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bIsOnTable = true;
	}
}

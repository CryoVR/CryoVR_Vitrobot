// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_GloveActor.h"
#include "Components/Boxcomponent.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_DewarActor.h"
#include "VB_VitrobotActor.h"
#include "VB_EthaneTankActor.h"
#include "VB_EthaneTipActor.h"
#include "VB_GridBoxTweezerActor.h"
#include "VB_VitrobotActor.h"
#include "VB_LevelScriptActor.h"

AVB_GloveActor::AVB_GloveActor()
{
	PickupMesh->SetVisibility(false);
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->SetupAttachment(PickupMesh);
}



void AVB_GloveActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	if (Cast<ATP_MotionController>(OtherActor) != nullptr)
	{
		//if (LSA != nullptr)
		//{
		//	if (LSA->GetStatus() == 0)
		//	{
		//		LSA->SetStatus(24);
		//	}
		//}
		Destroy();
	}
}

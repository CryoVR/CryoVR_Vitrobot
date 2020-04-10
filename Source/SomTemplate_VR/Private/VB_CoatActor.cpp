// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CoatActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_LevelScriptActor.h"

//AVB_CoatActor::AVB_CoatActor()
//{
//	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Coat(TEXT("StaticMesh'/Game/Models/DewarMesh.DewarMesh'"));
//	if (SM_Coat.Succeeded())
//	{
//		UStaticMesh* Asset = SM_Coat.Object;
//		meshComp->SetStaticMesh(Asset);
//		BoxComp->SetupAttachment(meshComp);
//
//	}
//	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
//	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
//	BoxComp->SetGenerateOverlapEvents(true);
//	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CoatActor::OnOverlapBegin);
//}
//
//
//
//void AVB_CoatActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
//	if (Cast<ATP_MotionController>(OtherActor) != nullptr)
//	{
//		/*if (LSA != nullptr)
//		{
//			if (LSA->GetStatus() == 1)
//			{
//				LSA->SetStatus(24);
//			}
//		}
//		Destroy();*/
//	}
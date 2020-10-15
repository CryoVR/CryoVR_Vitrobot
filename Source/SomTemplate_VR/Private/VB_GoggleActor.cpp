// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_GoggleActor.h"
#include "Public/Engine.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_LevelScriptActor.h"
#include "VirtualReality/TP_MotionController.h"

//AVB_GoggleActor::AVB_GoggleActor()
//{
//	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Goggle(TEXT("StaticMesh'/Game/Models/DewarMesh.DewarMesh'"));
//	if (SM_Goggle.Succeeded())
//	{
//		UStaticMesh* Asset = SM_Goggle.Object;
//		PickupMesh->SetStaticMesh(Asset);
//		BoxComp->SetupAttachment(PickupMesh);
//
//	}
//	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
//	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
//	BoxComp->SetGenerateOverlapEvents(true);
//	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_GoggleActor::OnOverlapBegin);
//}
//
//
//
//void AVB_GoggleActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
//	if (Cast<ATP_MotionController>(OtherActor) != nullptr)
//	{
//		//if (LSA != nullptr)
//		//{
//		//	if (LSA->GetStatus() == 0)
//		//	{
//		//		LSA->SetStatus(24);
//		//	}
//		//}
//		//Destroy();
//	}
//}
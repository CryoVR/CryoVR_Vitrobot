// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_LabGoggleActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_LevelScriptActor.h"
#include "VirtualReality/TP_MotionController.h"
#include "VirtualReality/TP_VirtualRealityPawn_Motion.h"



AVB_LabGoggleActor::AVB_LabGoggleActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Goggle(TEXT("StaticMesh'/Game/Test_Geometry/glass.glass'"));
	if (SM_Goggle.Succeeded())
	{
		UStaticMesh* Asset = SM_Goggle.Object;
		PickupMesh->SetStaticMesh(Asset);
		//BoxComp->SetupAttachment(PickupMesh);

	}
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_LabGoggleActor::OnOverlapBegin);
}



void AVB_LabGoggleActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	if (Cast<ATP_VirtualRealityPawn_Motion>(OtherActor) != nullptr)
	{
		Is_Weard = true;

		PickupMesh->SetVisibility(false);
		PickupMesh->SetGenerateOverlapEvents(false);
		BoxComp->SetGenerateOverlapEvents(false);
	}
}

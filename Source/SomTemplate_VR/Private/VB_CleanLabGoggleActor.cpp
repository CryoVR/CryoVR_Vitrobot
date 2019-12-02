// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanLabGoggleActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_LevelScriptActor.h"
#include "VirtualReality/TP_MotionController.h"
#include "VirtualReality/TP_VirtualRealityPawn_Motion.h"
#include "VB_CleanTableCompActor.h"



AVB_CleanLabGoggleActor::AVB_CleanLabGoggleActor()
{
	bISGoggleOnTable = false;

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

	PickupMesh->SetRelativeLocationAndRotation(FVector(-120.0f, 10.7f, 103.0f), FRotator(0.0f, 0.0f, 0.0f));
	PickupMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanLabGoggleActor::OnOverlapBegin);
}

void AVB_CleanLabGoggleActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bISGoggleOnTable = true;
		UE_LOG(LogTemp, Log, TEXT("=======================GoggleONTable!!!!!!!!!==========================="));
	}
}

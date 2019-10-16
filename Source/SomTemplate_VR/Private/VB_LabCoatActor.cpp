// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_LabCoatActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_LevelScriptActor.h"

AVB_LabCoatActor::AVB_LabCoatActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Coat(TEXT("StaticMesh'/Game/Test_Geometry/labcoat_labcoat.labcoat_labcoat'"));
	if (SM_Coat.Succeeded())
	{
		UStaticMesh* Asset = SM_Coat.Object;
		meshComp->SetStaticMesh(Asset);
		//BoxComp->SetupAttachment(meshComp);

	}
	//shapeComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	shapeComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	shapeComp->SetGenerateOverlapEvents(true);
	shapeComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_LabCoatActor::OnOverlapBegin);
}



void AVB_LabCoatActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	if (Cast<ATP_MotionController>(OtherActor) != nullptr)
	{
		if (LSA != nullptr)
		{
			if (LSA->GetStatus() == 34)
			{
				LSA->SetStatus(35);
			}
		}
		Destroy();
	}
}
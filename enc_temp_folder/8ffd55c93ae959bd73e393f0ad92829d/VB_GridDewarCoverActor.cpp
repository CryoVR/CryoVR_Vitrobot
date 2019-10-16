// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_GridDewarCoverActor.h"
#include "VB_GridDewarActor.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "Components/BoxComponent.h"
#include "VB_LevelScriptActor.h"
#include "VirtualReality/TP_MotionController.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

AVB_GridDewarCoverActor::AVB_GridDewarCoverActor() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Grid_Dewar_Cover.Grid_Dewar_Cover'"));
	if (SM_Pickup.Succeeded())
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);

		BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
		BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_GridDewarCoverActor::OnOverlapBegin);
		//BoxComp->OnComponentEndOverlap.AddDynamic(this, &AVB_GridDewarCoverActor::OnOverlapEnd);
		BoxComp->SetupAttachment(PickupMesh);
		BoxComp->SetRelativeLocation(FVector(0.0f, 0.0f, -0.4f));
		Cast<UBoxComponent>(BoxComp)->SetBoxExtent(FVector(6.0f, 6.0f, 1.0f));
	}
}

void AVB_GridDewarCoverActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVB_GridDewarActor *GridDewarActor = Cast<AVB_GridDewarActor>(OtherActor);
	if (GridDewarActor != nullptr)
	{
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(GridDewarActor->meshComp, AttachRules, FName("Cover_Socket"));
		//GridDewarActor->SetIsTouchable(false);
		AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
		if (LSA != nullptr)
		{
			if (LSA->GetStatus() == 32)
			{
				LSA->SetStatus(33);
			}
		}
		
	}

}

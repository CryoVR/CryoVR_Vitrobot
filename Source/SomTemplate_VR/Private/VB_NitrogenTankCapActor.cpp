// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_NitrogenTankCapActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Components/Scenecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_DewarActor.h"
#include "TimerManager.h"

AVB_NitrogenTankCapActor::AVB_NitrogenTankCapActor()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_NitrogenTankCapActor::OnOverlapBegin);
	BoxComp->SetRelativeLocation(FVector(0.0f, 0.0f, 1.9f));
	BoxComp->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.0625f));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_DewarCap(TEXT("StaticMesh'/Game/Models/NitrogenTankCapMesh.NitrogenTankCapMesh'"));
	if (SM_DewarCap.Succeeded())
	{
		UStaticMesh* Asset = SM_DewarCap.Object;
		PickupMesh->SetStaticMesh(Asset);
		BoxComp->SetupAttachment(PickupMesh);

	}
}



void AVB_NitrogenTankCapActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AVB_DewarActor>(OtherActor) != nullptr)
	{
		FName DewarSocket = "CapSocket";
		FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
		PickupMesh->AttachToComponent(OtherActor->GetRootComponent(), AttachmentTransformRules, DewarSocket);
	}
}



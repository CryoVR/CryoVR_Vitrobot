// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_WorkstationActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"

AVB_WorkstationActor::AVB_WorkstationActor() 
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_WorkstationActor::OnOverlapBegin);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Test_Geometry/Workstation_Vitrobot_1_3size.Workstation_Vitrobot_1_3size'"));
	if (SM_Pickup.Succeeded())
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);
		BoxComp->SetupAttachment(PickupMesh);
	}
}

void AVB_WorkstationActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, FrozenFX, GetActorLocation());
}

void AVB_WorkstationActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayEffects();
}


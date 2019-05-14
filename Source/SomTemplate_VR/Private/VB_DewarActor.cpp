// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_DewarActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_NitrogenTankCapActor.h"

AVB_DewarActor::AVB_DewarActor()
{
	BoxCompCap = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCompCap"));
	BoxCompCap->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCompCap->OnComponentBeginOverlap.AddDynamic(this, &AVB_DewarActor::OnOverlapBegin);
	BoxCompCap->OnComponentEndOverlap.AddDynamic(this, &AVB_DewarActor::OnOverlapEnd);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Dewar(TEXT("StaticMesh'/Game/Models/DewarMesh.DewarMesh'"));
	if (SM_Dewar.Succeeded())
	{
		UStaticMesh* Asset = SM_Dewar.Object;
		PickupMesh->SetStaticMesh(Asset);
		BoxCompCap->SetupAttachment(PickupMesh);

	}
}


void AVB_DewarActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, FrozenFX, GetActorLocation());
}


void AVB_DewarActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AVB_NitrogenTankCapActor>(OtherActor) != nullptr)
	{
		FrozenFX->SetVisibility(false);
	}
}


void AVB_DewarActor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AVB_NitrogenTankCapActor>(OtherActor) != nullptr)
	{
		FrozenFX->SetVisibility(true);
	}
}

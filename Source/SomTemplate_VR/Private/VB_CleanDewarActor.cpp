// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanDewarActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_NitrogenTankCapActor.h"
#include "VB_LevelScriptActor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_CleanTableCompActor.h"

AVB_CleanDewarActor::AVB_CleanDewarActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Dewar(TEXT("StaticMesh'/Game/Models/DewarMesh.DewarMesh'"));
	if (SM_Dewar.Succeeded())
	{
		UStaticMesh* Asset = SM_Dewar.Object;
		PickupMesh->SetStaticMesh(Asset);

	}
	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanDewarActor::OnOverlapBegin);
}

void AVB_CleanDewarActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bIsOnTable = true;
	}
}

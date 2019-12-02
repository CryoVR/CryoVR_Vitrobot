// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanFreezingDewarActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "VB_DewarActor.h"
#include "VB_LevelScriptActor.h"
#include "VB_GridBoxTweezerActor.h"
#include "VB_CleanTableCompActor.h"

AVB_CleanFreezingDewarActor::AVB_CleanFreezingDewarActor()
{
	bISCleanFDewarOnTable = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanFDewar(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/FreezeDewar.FreezeDewar'"));
	if (SM_CleanFDewar.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_CleanFDewar.Object);
	}
	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanFreezingDewarActor::OnOverlapBegin);

}

void AVB_CleanFreezingDewarActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bISCleanFDewarOnTable = true;
		UE_LOG(LogTemp, Log, TEXT("=======================FDewarONTable!!!!!!!!!==========================="));
	}
}

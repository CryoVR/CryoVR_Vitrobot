// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanPetridishCoverActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VB_PetridishActor.h"
#include "VB_StaticActor.h"
#include "VB_LevelScriptActor.h"
#include "Materials/MaterialInstanceConstant.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_CleanTableCompActor.h"
#include "VB_CleanPetridishActor.h"

AVB_CleanPetridishCoverActor::AVB_CleanPetridishCoverActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanPetridishCover(TEXT("StaticMesh'/Game/Models/GridHolderUMesh.GridHolderUMesh'"));
	if (SM_CleanPetridishCover.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_CleanPetridishCover.Object);
	}

	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->SetGenerateOverlapEvents(true);

	covercollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	covercollisionComp->SetupAttachment(PickupMesh);
	covercollisionComp->SetBoxExtent(FVector(4.5f, 4.5f, 1.0f));
	covercollisionComp->SetRelativeLocation(FVector(0.0f, 0.0f, 0.5f));
	covercollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanPetridishCoverActor::OnOverlapBegin);

}

void AVB_CleanPetridishCoverActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanPetridishActor* CleanpetridishActor = Cast<AVB_CleanPetridishActor>(OtherActor);

	if (CleanpetridishActor != nullptr) {
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		PickupMesh->SetSimulatePhysics(false);
		GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachRules, FName("UpperCoverSocket"));
	}
}

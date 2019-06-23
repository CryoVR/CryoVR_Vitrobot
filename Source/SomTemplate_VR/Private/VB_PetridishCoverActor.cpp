// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PetridishCoverActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VB_PetridishActor.h"
#include "VB_StaticActor.h"
#include "Materials/MaterialInstanceConstant.h"

AVB_PetridishCoverActor::AVB_PetridishCoverActor() {
	
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_PetridishCover(TEXT("StaticMesh'/Game/Models/GridHolderUMesh.GridHolderUMesh'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MI_GlassMatInst(TEXT("MaterialInstanceConstant'/Game/Models/01GridHolderMat_Inst.01GridHolderMat_Inst'"));

	if (SM_PetridishCover.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_PetridishCover.Object);
	}
	if (MI_GlassMatInst.Succeeded()) {
		PickupMesh->SetMaterial(0, MI_GlassMatInst.Object);
	}

	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->SetGenerateOverlapEvents(false);

	covercollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	covercollisionComp->SetupAttachment(PickupMesh);
	covercollisionComp->SetBoxExtent(FVector(4.5f, 4.5f, 1.0f));
	covercollisionComp->SetRelativeLocation(FVector(0.0f, 0.0f, 0.5f));
	covercollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PetridishCoverActor::OnOverlapBegin);
	covercollisionComp->OnComponentEndOverlap.AddDynamic(this, &AVB_PetridishCoverActor::OnOverlapEnd);

}


void AVB_PetridishCoverActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{ 
	AVB_PetridishActor* petridishActor = Cast<AVB_PetridishActor>(OtherActor);

	if (petridishActor != nullptr) {
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		PickupMesh->SetSimulatePhysics(false);
		GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachRules, FName("UpperCoverSocket"));
		petridishActor->setState(false);
	}
}

void AVB_PetridishCoverActor::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	AVB_PetridishActor* petridishActor = Cast<AVB_PetridishActor>(OtherActor);
	if (petridishActor != nullptr) {
		petridishActor->setState(true);
	}
}

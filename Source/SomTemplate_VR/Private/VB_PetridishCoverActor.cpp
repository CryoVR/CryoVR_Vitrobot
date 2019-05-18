// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PetridishCoverActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VB_PetridishActor.h"

AVB_PetridishCoverActor::AVB_PetridishCoverActor() {
	
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_PetridishCover(TEXT("StaticMesh'/Game/Models/GridHolderUMesh.GridHolderUMesh'"));

	if (SM_PetridishCover.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_PetridishCover.Object);
	}

	covercollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	covercollisionComp->SetupAttachment(PickupMesh);
	covercollisionComp->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.1f));
	covercollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PetridishCoverActor::OnOverlapBegin);

}


void AVB_PetridishCoverActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{ 
	AVB_PetridishActor* petridishActor = Cast<AVB_PetridishActor>(OtherActor);
	if (petridishActor != nullptr) {
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachRules, FName("UpperCoverSocket"));
	}
}

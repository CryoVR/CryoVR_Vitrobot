// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PetridishCoverActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"

AVB_PetridishCoverActor::AVB_PetridishCoverActor() {
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	boxComp->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.1f));
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PetridishCoverActor::OnOverlapBegin);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_PetridishCover(TEXT("StaticMesh'/Game/Models/GridHolderUMesh.GridHolderUMesh'"));

	if (SM_PetridishCover.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_PetridishCover.Object);
		boxComp->SetupAttachment(PickupMesh);
	}
}

UBoxComponent * AVB_PetridishCoverActor::Get_petridishCover()
{
	return boxComp;
}

void AVB_PetridishCoverActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{ 

}

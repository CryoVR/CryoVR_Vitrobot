// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanPetridishActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "VB_CleanTableCompActor.h"

AVB_CleanPetridishActor::AVB_CleanPetridishActor()
{

	bISCleanPetridishOnTable = false;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("PetridishComp"));
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	boxComp->SetBoxExtent(FVector(4.5f, 4.5f, 1.0f));
	boxComp->SetRelativeLocation(FVector(0.0f, 0.0f, 1.5f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanPetridish(TEXT("StaticMesh'/Game/Models/GridHolderDMesh.GridHolderDMesh'"));
	if (SM_CleanPetridish.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_CleanPetridish.Object);
		boxComp->SetupAttachment(PickupMesh);
	}
	

	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanPetridishActor::OnOverlapBegin);
}

void AVB_CleanPetridishActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bISCleanPetridishOnTable = true;
		UE_LOG(LogTemp, Log, TEXT("=======================PetridishONTable!!!!!!!!!==========================="));
	}
}

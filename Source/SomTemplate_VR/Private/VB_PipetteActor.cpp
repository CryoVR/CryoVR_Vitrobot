// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PipetteActor.h"
#include "Components/Spherecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "VB_SampleTubeActor.h"

AVB_PipetteActor::AVB_PipetteActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PipetteActor::OnOverlapBegin);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> parent of 154402c... Pipet_Change
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
	UStaticMesh* Asset = SM_Pickup.Object;
	PickupMesh->SetStaticMesh(Asset);
=======
>>>>>>> parent of a832acb... Pippet_test

	

}


void AVB_PipetteActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	if (Cast<AVB_SampleTubeActor>(OtherActor) != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Activated"));
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
		static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
		UStaticMesh* Asset = SM_Pickup.Object;

		PickupMesh->SetStaticMesh(Asset);
>>>>>>> 8e9b7b433f6da1825b768d591449f82a11b2f927
=======
>>>>>>> parent of 154402c... Pipet_Change

=======
>>>>>>> parent of a832acb... Pippet_test
	}

}



//This is an potential function that may be used in the future
/*
void AVB_PipetteActor::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("Activated"));
}
*/

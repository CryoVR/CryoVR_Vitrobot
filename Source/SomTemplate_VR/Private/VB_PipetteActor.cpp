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
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
	UStaticMesh* Asset = SM_Pickup.Object;
=======
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Tweezer.Tweezer'"));
	UStaticMesh* Asset = SM_Pickup.Object;

>>>>>>> 8e9b7b433f6da1825b768d591449f82a11b2f927
	PickupMesh->SetStaticMesh(Asset);

	

}


void AVB_PipetteActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	if (Cast<AVB_SampleTubeActor>(OtherActor) != nullptr)
	{	
		static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MI_SmallCubes(TEXT("MaterialInstanceConstant'/Game/VirtualReality/Materials/MI_SmallCubes.MI_SmallCubes'"));
		UMaterialInstanceConstant* Material = MI_SmallCubes.Object; 
		PickupMesh->SetMaterial(5, Material);
		UE_LOG(LogTemp, Log, TEXT("Activated"));
<<<<<<< HEAD
=======
		static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
		UStaticMesh* Asset = SM_Pickup.Object;

		PickupMesh->SetStaticMesh(Asset);
>>>>>>> 8e9b7b433f6da1825b768d591449f82a11b2f927

	}
	

}



//This is an potential function that may be used in the future
/*
void AVB_PipetteActor::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("Activated"));
}
*/

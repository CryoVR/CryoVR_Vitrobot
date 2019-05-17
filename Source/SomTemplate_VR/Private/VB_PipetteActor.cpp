// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PipetteActor.h"
#include "Components/Spherecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "VB_SampleTubeActor.h"

class UPrimitiveComponent;

AVB_PipetteActor::AVB_PipetteActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PipetteActor::OnOverlapBegin);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
	if (SM_Pickup.Succeeded()) 
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);
		SphereComp->SetupAttachment(PickupMesh);
		SphereComp->SetRelativeLocation(FVector(0.0f, 0.0f, -15.02f));
		SphereComp->SetRelativeScale3D(FVector(0.007f));
		//This is another way of setting scale;
		//Cast<USphereComponent>(SphereComp)->SetSphereRadius();
	}
}


void AVB_PipetteActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	//When overlaps with the sample tube
	if (Cast<AVB_SampleTubeActor>(OtherActor) != nullptr)
	{
		//This one is for the constructor function.Temporary can not be used.
		//static ConstructorHelpers::FObjectFinder<UMaterial> MI_SmallCubes(TEXT("MaterialInstanceConstant'/Game/Models/Pipet_body01Mat.Pipet_body01Mat'"));

		UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(PickupMesh->GetMaterial(0), this);
		DynamicMaterial->SetVectorParameterValue("BodyColor", FLinearColor::Blue);
		

		if (DynamicMaterial != nullptr) 
		{	
			PickupMesh->SetMaterial(4, DynamicMaterial);
			UE_LOG(LogTemp, Log, TEXT("Activated"));
		}
	}
}





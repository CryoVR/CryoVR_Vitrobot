// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PipetteActor.h"
#include "Components/Spherecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "VB_SampleTubeActor.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_TweezerActor.h"
#include "VB_PippetHolderActor.h"

class UPrimitiveComponent;

AVB_PipetteActor::AVB_PipetteActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PipetteActor::OnOverlapBegin);

	HandcapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PipetteCapsuleComp"));
	HandcapsuleComp->SetGenerateOverlapEvents(true);
	HandcapsuleComp->SetGenerateOverlapEvents(ECollisionEnabled::QueryOnly);
	HandcapsuleComp->SetCapsuleSize(0.5f, 7.0f);
	HandcapsuleComp->SetRelativeLocation(FVector(0.0f, 0.0f, 1.0f));
	HandcapsuleComp->SetupAttachment(PickupMesh);
	HandcapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PipetteActor::OnPipetHandOverlapBegin);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
	if (SM_Pickup.Succeeded()) 
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);
		PickupMesh->SetRelativeScale3D(FVector(1.35f, 1.35f, 1.35f));
		SphereComp->SetupAttachment(PickupMesh);
		SphereComp->SetRelativeLocation(FVector(0.0f, 0.0f, -15.02f));
		SphereComp->SetRelativeScale3D(FVector(0.007f));
		//This is another way of setting scale;
		//Cast<USphereComponent>(SphereComp)->SetSphereRadius();
	}
}


void AVB_PipetteActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	

	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(PickupMesh->GetMaterial(0), this);
	UMaterialInstanceDynamic* DynamicMaterial_1 = UMaterialInstanceDynamic::Create(PickupMesh->GetMaterial(0), this);
	DynamicMaterial->SetVectorParameterValue("BodyColor", FLinearColor::Blue);
	DynamicMaterial_1->SetVectorParameterValue("BodyColor", FLinearColor::Transparent);

	//When overlaps with the sample tube
	if (Cast<AVB_SampleTubeActor>(OtherActor) != nullptr)
	{
		//This one is for the constructor function.Temporary can not be used.
		//static ConstructorHelpers::FObjectFinder<UMaterial> MI_SmallCubes(TEXT("MaterialInstanceConstant'/Game/Models/Pipet_body01Mat.Pipet_body01Mat'"));

		
		

		if (DynamicMaterial != nullptr) 
		{	
			PickupMesh->SetMaterial(4, DynamicMaterial);
			UE_LOG(LogTemp, Log, TEXT("Activated"));
		}
	}

	AVB_TweezerActor* tweezerGrid = Cast<AVB_TweezerActor>(OtherActor);
	if (tweezerGrid != nullptr) {
		if (tweezerGrid->m_isGridAttached && tweezerGrid->tweezer_grid == OtherComp) 
		{
			UE_LOG(LogTemp, Log, TEXT("=======================Code Executed01==========================="));
			PickupMesh->SetMaterial(4, DynamicMaterial_1);
		}
	}

	
}

void AVB_PipetteActor::OnPipetHandOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("Pipet_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float>{ -3.0f, 1.0f }, Cast<ATP_MotionController>(OtherActor));
	}

	AVB_PippetHolderActor* holder = Cast<AVB_PippetHolderActor>(OtherActor);
	if (holder != nullptr) {
		UE_LOG(LogTemp, Log, TEXT("=======================Holder Attach==========================="));
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachRules, FName("Holder_Socket_Pippet"));
	}
}





// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PipetteActor.h"
#include "Components/Spherecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "VB_SampleTubeActor.h"
#include "VB_TweezerActor.h"
#include "VB_VitrobotActor.h"
#include "VB_LevelScriptActor.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "VB_PippetHolderActor.h"

class UPrimitiveComponent;

AVB_PipetteActor::AVB_PipetteActor()
{	
	PrimaryActorTick.bCanEverTick = true;
	bp_PipetteGrab = false;
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
	static ConstructorHelpers::FObjectFinder<UMaterial> SM_M(TEXT("/Game/Test_Geometry/Test_Textures/defaultMat.defaultMat"));

	if (SM_Pickup.Succeeded()) 
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);
		PickupMesh->SetRelativeScale3D(FVector(1.35f, 1.35f, 1.35f));
		//PickupMesh->SetWorldLocation(FVector(56.5103378f, 52.3637772f, 129.0230255f));
		//PickupMesh->SetWorldRotation(FRotator(0.0f, 100.0000229f, 303.7501831f));
		SphereComp->SetupAttachment(PickupMesh);
		SphereComp->SetRelativeLocation(FVector(0.0f, 0.0f, -15.02f));
		SphereComp->SetRelativeScale3D(FVector(0.007f));
		//This is another way of setting scale;
		//Cast<USphereComponent>(SphereComp)->SetSphereRadius();
	}

	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));
}


void AVB_PipetteActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	

	//UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(PickupMesh->GetMaterial(0), this);
	//UMaterialInstanceDynamic* DynamicMaterial_1 = UMaterialInstanceDynamic::Create(PickupMesh->GetMaterial(0), this);
	//DynamicMaterial->SetVectorParameterValue("BodyColor", FLinearColor::Blue);

	//When overlaps with the sample tube & tweezer
	if (Cast<AVB_SampleTubeActor>(OtherActor) != nullptr)
	{
	   	//if (DynamicMaterial != nullptr) 
		//{	
			PickupMesh->SetMaterial(4, OffMaterial);
			//PickupMesh->SetRenderCustomDepth(true);
			AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
			if (LSA != nullptr)
			{
				if (LSA->GetStatus() == 17)
				{
					LSA->SetStatus(18);
				}
			}
		//}
	}

	if (Cast<AVB_TweezerActor>(OtherActor))
	{
		if (OtherActor != nullptr)
		{
			PickupMesh->SetMaterial(4, OnMaterial);
			AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
			if (LSA != nullptr)
			{
				if (LSA->GetStatus() == 18)
				{
					LSA->SetStatus(20);
				}
			}
		}	
	}
	
}

void AVB_PipetteActor::OnPipetHandOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("Pipet_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float>{ -3.0f, 1.0f }, Cast<ATP_MotionController>(OtherActor));
		AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());

	}

	AVB_PippetHolderActor* holder = Cast<AVB_PippetHolderActor>(OtherActor);
	if (holder != nullptr) {
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachRules, FName("Holder_Socket_Pippet"));
	}
}

void AVB_PipetteActor::Tick(float DeltaTime)
{
	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());

	if (m_isGrab == true)
	{
		if (LSA->GetStatus() == 16)
		{
			LSA->SetStatus(17);
		}
	}
}




// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_GridMetalTubeActor.h"
#include "VB_GridDewarActor.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_LevelScriptActor.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

AVB_GridMetalTubeActor::AVB_GridMetalTubeActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Grid_Metal_Tube.Grid_Metal_Tube'"));
	if (SM_Pickup.Succeeded())
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);

		CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
		CapsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_GridMetalTubeActor::OnOverlapBegin);
		CapsuleComp->SetupAttachment(PickupMesh);
		CapsuleComp->SetRelativeLocation(FVector(1.4185486f, 0.0f, -0.9034729f));
		CapsuleComp->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
		CapsuleComp->SetCapsuleSize(4.5f, 1.5f);

		CapsuleBodyComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleBodyComp"));
		CapsuleBodyComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CapsuleBodyComp->SetupAttachment(PickupMesh);
		CapsuleBodyComp->SetRelativeLocation(FVector(8.3756676f, -2.4736633f, -44.2146759f));
		CapsuleBodyComp->SetCapsuleSize(20.0f, 4.0f);
	}
}

void AVB_GridMetalTubeActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVB_GridDewarActor *GridDewarActor = Cast<AVB_GridDewarActor>(OtherActor);
	if (GridDewarActor != nullptr)
	{	
			FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
			GetRootComponent()->AttachToComponent(GridDewarActor->meshComp, AttachRules, FName("MetalTube_Socket"));
			AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
			if (LSA != nullptr)
			{
				if (LSA->GetStatus() == 32)
				{
					LSA->SetStatus(33);
				}
			}
		
	}
}

void AVB_GridMetalTubeActor::OnHandOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor) != nullptr)
	{
		AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
		if (LSA != nullptr)
		{
			if (LSA->GetStatus() == 30)
			{
				LSA->SetStatus(31);
			}
		}
	}
}

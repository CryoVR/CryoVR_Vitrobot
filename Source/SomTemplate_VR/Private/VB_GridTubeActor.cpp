// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_GridTubeActor.h"
#include "VB_GridMetalTubeActor.h"
#include "VB_GridBoxTweezerActor.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "VB_LevelScriptActor.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

AVB_GridTubeActor::AVB_GridTubeActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Grid_Tube.Grid_Tube'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_GridBox(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Grid_Box.Grid_Box'"));
	if (SM_Pickup.Succeeded())
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);

		CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
		CapsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_GridTubeActor::OnOverlapBegin);
		CapsuleComp->SetupAttachment(PickupMesh);
		CapsuleComp->SetRelativeLocation(FVector(0.0f, 0.0f, -1.7840805f));
		CapsuleComp->SetCapsuleSize(3.0f, 1.5f);

		CapsuleBodyComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleBodyComp"));
		CapsuleBodyComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CapsuleBodyComp->SetupAttachment(PickupMesh);
		CapsuleBodyComp->SetRelativeLocation(FVector(0.0f, -2.36f, -22.6f));
		CapsuleBodyComp->SetCapsuleSize(4.4f, 2.0f);
		CapsuleBodyComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_GridTubeActor::OnTweezerOverlapBegin);

		GridBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grid_Box"));
		GridBox->SetupAttachment(PickupMesh);
		GridBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GridBox->SetRelativeLocation(FVector(0.0f, -2.3502636f, -25.5601959f));
		GridBox->SetRelativeScale3D(FVector(1.4f, 1.4f, 0.7f));
		GridBox->SetRelativeRotation(FRotator(40.0f, 0.0f, 0.0f));
		GridBox->SetVisibility(false);
		if (SM_GridBox.Succeeded())
		{
			UStaticMesh *Gridbox = SM_GridBox.Object;
			GridBox->SetStaticMesh(Gridbox);
		}

	}
}

void AVB_GridTubeActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVB_GridMetalTubeActor *GridMetalTubeActor = Cast<AVB_GridMetalTubeActor>(OtherActor);
	if (GridMetalTubeActor != nullptr)
	{
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(GridMetalTubeActor->PickupMesh, AttachRules, FName("GridTube_Socket"));
		AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
		if (LSA != nullptr)
		{
			if (LSA->GetStatus() == 31)
			{
				LSA->SetStatus(32);
			}
		}
	}
	
}

void AVB_GridTubeActor::OnTweezerOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVB_GridBoxTweezerActor *GBTweezer = Cast<AVB_GridBoxTweezerActor>(OtherActor);
	if (GBTweezer != nullptr)
	{
		GridBox->SetVisibility(true);
		AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
		if (LSA != nullptr)
		{
			if (LSA->GetStatus() == 28)
			{
				LSA->SetStatus(29);
			}
		}
	}
}

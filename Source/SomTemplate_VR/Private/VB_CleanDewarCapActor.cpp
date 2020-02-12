// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanDewarCapActor.h"
#include "Public/Engine.h"
#include "Components/CapsuleComponent.h"
#include "Components/Scenecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_DewarActor.h"
#include "TimerManager.h"
#include "VB_LevelScriptActor.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_CleanTableCompActor.h"
#include "VB_CleanDewarActor.h"

AVB_CleanDewarCapActor::AVB_CleanDewarCapActor()
{
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanDewarCapActor::OnOverlapBegin);
	CapsuleComp->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	CapsuleComp->SetRelativeScale3D(FVector(0.08f, 0.14f, 0.09f));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanDewarCap(TEXT("StaticMesh'/Game/Models/NitrogenTankCapMesh.NitrogenTankCapMesh'"));
	if (SM_CleanDewarCap.Succeeded())
	{
		UStaticMesh* Asset = SM_CleanDewarCap.Object;
		PickupMesh->SetStaticMesh(Asset);
		CapsuleComp->SetupAttachment(PickupMesh);

	}

	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->SetGenerateOverlapEvents(false);
}

void AVB_CleanDewarCapActor::ResetActorState()
{
	SetActorTransform(m_OriginalTransform);
	PickupMesh->SetSimulatePhysics(true);
}

void AVB_CleanDewarCapActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<AVB_CleanDewarActor>(OtherActor) != nullptr)
	{
		FName DewarSocket = "CapSocket";
		PickupMesh->SetSimulatePhysics(false);
		FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true);
		GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachmentTransformRules, DewarSocket);
	}

	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("TankCap_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.33f, 0.8f}, Cast<ATP_MotionController>(OtherActor));


	}
}


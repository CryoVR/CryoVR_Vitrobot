// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanPipetteActor.h"
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
#include "VB_CleanTableCompActor.h"

AVB_CleanPipetteActor::AVB_CleanPipetteActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
	if (SM_Pickup.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_Pickup.Object);
	}

	HandcapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PipetteCapsuleComp"));
	HandcapsuleComp->SetGenerateOverlapEvents(true);
	HandcapsuleComp->SetGenerateOverlapEvents(ECollisionEnabled::QueryOnly);
	HandcapsuleComp->SetCapsuleSize(0.5f, 7.0f);
	HandcapsuleComp->SetRelativeLocation(FVector(0.0f, 0.0f, 1.0f));
	HandcapsuleComp->SetupAttachment(PickupMesh);
	HandcapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanPipetteActor::OnPipetHandOverlapBegin);

	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanPipetteActor::OnOverlapBegin);
}

void AVB_CleanPipetteActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bIsOnTable = true;
		
	}
}

void AVB_CleanPipetteActor::OnPipetHandOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("Pipet_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float>{ -3.0f, 1.0f }, Cast<ATP_MotionController>(OtherActor));
	}
}

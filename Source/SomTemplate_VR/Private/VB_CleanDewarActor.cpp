// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanDewarActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_NitrogenTankCapActor.h"
#include "VB_LevelScriptActor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_CleanTableCompActor.h"

AVB_CleanDewarActor::AVB_CleanDewarActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Dewar(TEXT("StaticMesh'/Game/Models/DewarMesh.DewarMesh'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Cap(TEXT("StaticMesh'/Game/Models/NitrogenTankCapMesh.NitrogenTankCapMesh'"));
	if (SM_Dewar.Succeeded())
	{
		UStaticMesh* Asset = SM_Dewar.Object;
		PickupMesh->SetStaticMesh(Asset);

	}

	if (SM_Cap.Succeeded())
	{	
		CapComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cap"));
		UStaticMesh* Asset1 = SM_Cap.Object;
		CapComp->SetStaticMesh(Asset1);
		CapComp->SetupAttachment(PickupMesh);
	}
	HandcapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("DewarCapsuleComp"));
	HandcapsuleComp->SetGenerateOverlapEvents(true);
	HandcapsuleComp->SetGenerateOverlapEvents(ECollisionEnabled::QueryOnly);
	HandcapsuleComp->SetCapsuleSize(2.5f, 10.0f);
	HandcapsuleComp->SetRelativeLocation(FVector(-10.0f, 0.0f, 20.0f));
	HandcapsuleComp->SetupAttachment(PickupMesh);
	HandcapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanDewarActor::OnHandOverlapBegin);

	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanDewarActor::OnOverlapBegin);
}

void AVB_CleanDewarActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bIsOnTable = true;
	}
}

void AVB_CleanDewarActor::OnHandOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor)) {
		UE_LOG(LogTemp, Log, TEXT("=======================clean_GESTURE!!!!!!==========================="));
		UpdateHandGuestureFunc(true, FName("Dewar_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {3.0f, 0.0f}, Cast<ATP_MotionController>(OtherActor));
	}
}

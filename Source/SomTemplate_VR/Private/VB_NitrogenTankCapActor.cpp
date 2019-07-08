// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_NitrogenTankCapActor.h"
#include "Public/Engine.h"
#include "Components/CapsuleComponent.h"
#include "Components/Scenecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_DewarActor.h"
#include "TimerManager.h"
#include "VirtualReality/TP_MotionController.h"

AVB_NitrogenTankCapActor::AVB_NitrogenTankCapActor()
{
	BoxComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_NitrogenTankCapActor::OnOverlapBegin);
	BoxComp->SetRelativeLocation(FVector(0.0f, 0.0f, 1.9f));
	BoxComp->SetRelativeScale3D(FVector(0.08f, 0.14f, 0.09f));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_DewarCap(TEXT("StaticMesh'/Game/Models/NitrogenTankCapMesh.NitrogenTankCapMesh'"));
	if (SM_DewarCap.Succeeded())
	{
		UStaticMesh* Asset = SM_DewarCap.Object;
		PickupMesh->SetStaticMesh(Asset);
		BoxComp->SetupAttachment(PickupMesh);

	}
}



void AVB_NitrogenTankCapActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AVB_DewarActor>(OtherActor) != nullptr)
	{
		FName DewarSocket = "CapSocket";
		PickupMesh->SetSimulatePhysics(false);
		FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true);
		//UE_LOG(LogTemp, Log, TEXT("=======================Nitrogen Tank============================"));
		GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachmentTransformRules, DewarSocket);
		//AttachToActor(OtherActor, AttachmentTransformRules, DewarSocket);
	}

	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("TankCap_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.33f, 0.8f}, Cast<ATP_MotionController>(OtherActor));
	}
}








// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_WorkstationActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_DewarActor.h"
#include "VB_VitrobotActor.h"
#include "VB_EthaneTankActor.h"
#include "VB_EthaneTipActor.h"
#include "VB_VitrobotActor.h"
#include "VirtualReality/TP_MotionController.h"

AVB_WorkstationActor::AVB_WorkstationActor() 
{
	isEthaneAdded = false;
	PickupMesh->SetGenerateOverlapEvents(true);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_WorkstationActor::OnOverlapBegin);
	BoxComp->SetRelativeLocation(FVector(0.0f, 0.0f, 3.26f));
	BoxComp->SetRelativeScale3D(FVector(0.22f, 0.22f, 0.11f));
	//BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_WorkstationActor::OnVitrobotOverlapBegin);
	

	/*capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("capsuleComp"));
	capsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	capsuleComp->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	capsuleComp->SetupAttachment(PickupMesh);
	capsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_WorkstationActor::OnTipOverlapBegin);*/

	


	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Test_Geometry/Workstation_Vitrobot_1_3size.Workstation_Vitrobot_1_3size'"));
	if (SM_Pickup.Succeeded())
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);
		BoxComp->SetupAttachment(PickupMesh);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_Effect(TEXT("ParticleSystem'/Game/Test_Geometry/Test_Particle/P_Steam_Lit.P_Steam_Lit'"));
	if (P_Effect.Succeeded())
	{
		FrozenFX = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FrozenEffect"));
		FrozenFX->SetTemplate(P_Effect.Object);
		FrozenFX->SetVisibility(false);
		FrozenFX->SetupAttachment(PickupMesh);
	}
}

void AVB_WorkstationActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	if (Cast<AVB_DewarActor>(OtherActor) != nullptr)
	{
		FrozenFX->SetVisibility(true);
		//PickupMesh->SetSimulatePhysics(false);
	}

	UE_LOG(LogTemp, Log, TEXT("=======================Vitrobot==========================="));
	AVB_VitrobotActor* VitrobotActor = Cast<AVB_VitrobotActor>(OtherActor);
	if (VitrobotActor != nullptr) {
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(VitrobotActor->WorkstationHolder, AttachRules, FName("workstationSocket"));
		UE_LOG(LogTemp, Log, TEXT("=======================Code Executed01==========================="));
	}

	//Hand gesture setting
	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("WorkStation_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.25f, 1.0f}, Cast<ATP_MotionController>(OtherActor));
	}
}

//void AVB_WorkstationActor::OnTipOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	AVB_EthaneTipActor* EthaneTipActor = Cast<AVB_EthaneTipActor>(OtherActor);
//	if (EthaneTipActor != nullptr) {
//		if (EthaneTipActor->ethaneTipCollisionComp == OtherComp && EthaneTipActor->ethaneParticle->IsActive()) {
//			//UE_LOG(LogTemp, Log, TEXT("=======================Code Executed01111111111111==========================="));
//			isEthaneAdded = !isEthaneAdded;
//		}
//	}
//}



 
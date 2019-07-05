// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019

#include "VB_EthaneTipActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_EthaneTankActor.h"
#include "VirtualReality/TP_MotionController.h"


AVB_EthaneTipActor::AVB_EthaneTipActor() {

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_EthaneTipMesh(TEXT("StaticMesh'/Game/Models/EthaneTip.EthaneTip'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PAR_EthaneParticle(TEXT("ParticleSystem'/Game/Particles/EthaneSplash_P.EthaneSplash_P'"));
	//Set up base mesh
	if (SM_EthaneTipMesh.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_EthaneTipMesh.Object);
	}
	PickupMesh->SetRelativeScale3D(FVector(0.2f));
	PickupMesh->SetGenerateOverlapEvents(false);
	PickupMesh->SetSimulatePhysics(true);
	

	ethaneTipCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("EthaneTipCollision"));
	ethaneTipCollisionComp->SetupAttachment(PickupMesh);
	ethaneTipCollisionComp->SetCapsuleSize(2.0f, 16.0f);
	ethaneTipCollisionComp->SetRelativeLocation(FVector(0.0f, 0.0f, -15.0f));
	ethaneTipCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_EthaneTipActor::OnActorBeginOverlap);

	ethaneTipCapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TipCapsuleComp"));
	ethaneTipCapsuleComp->SetGenerateOverlapEvents(true);
	ethaneTipCapsuleComp->SetGenerateOverlapEvents(ECollisionEnabled::QueryOnly);
	ethaneTipCapsuleComp->SetCapsuleSize(0.4f, 5.0f);
	ethaneTipCapsuleComp->SetRelativeLocation(FVector(0.0f, 0.0f, 0.3f));
	ethaneTipCapsuleComp->SetupAttachment(PickupMesh);
	ethaneTipCapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_EthaneTipActor::OnActorBeginOverlap);

	ethaneParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EthaneParticle"));
	ethaneParticle->SetupAttachment(PickupMesh);
	ethaneParticle->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	if (PAR_EthaneParticle.Succeeded()) {
		ethaneParticle->SetTemplate(PAR_EthaneParticle.Object);
	}
	ethaneParticle->SetActive(false);
	ethaneParticle->SetAutoActivate(false);

}

void AVB_EthaneTipActor::OnActorBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_EthaneTankActor* ethaneTankRef = Cast<AVB_EthaneTankActor>(OtherActor);
	if (ethaneTankRef != nullptr) {
		UPrimitiveComponent* comp = Cast<UPrimitiveComponent>(ethaneTankRef->GetComponentByIndex(3));
		if (comp != nullptr && comp == OtherComp) {
			FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
			PickupMesh->SetSimulatePhysics(false);
			GetRootComponent()->AttachToComponent(OtherActor->GetRootComponent(), AttachRules, FName("TipSocket"));
			//UE_LOG(LogTemp, Log, TEXT("======================Test+==================="));
		}
	}

	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("Tip_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.0f, 0.5f}, Cast<ATP_MotionController>(OtherActor));
	}
}

//void AVB_EthaneTipActor::OnTipBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	if (Cast<ATP_MotionController>(OtherActor)) {
//		UpdateHandGuestureFunc(true, FName("Tip_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.0f, 0.5f}, Cast<ATP_MotionController>(OtherActor));
//	}
//}

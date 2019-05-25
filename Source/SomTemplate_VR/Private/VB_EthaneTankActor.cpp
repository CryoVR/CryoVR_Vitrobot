 // Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_EthaneTankActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"
#include "Materials/Material.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_EthaneTipActor.h"
#include "Particles/ParticleSystemComponent.h"



AVB_EthaneTankActor::AVB_EthaneTankActor() {
	PrimaryActorTick.bCanEverTick = false;

	
	ConstructorHelpers::FObjectFinder<UMaterial> M_EthaneTankMat(TEXT("Material'/Game/Models/EthaneTank_MainMat.EthaneTank_MainMat'"));
	if (M_EthaneTankMat.Succeeded()) {
		meshComp->SetMaterial(4, M_EthaneTankMat.Object);
	} 

	ethaneTipPosCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("EthaneTipCollision"));
	ethaneTipPosCollisionComp->SetupAttachment(meshComp);
	ethaneTipPosCollisionComp->SetCapsuleSize(1.0f, 1.0f);
	ethaneTipPosCollisionComp->SetRelativeLocation(FVector(-29.33f, 0.75f, 42.8f));

	shapeComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_EthaneTankActor::OnOverlapBegin);
	secondKnobCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_EthaneTankActor::OnOverlapBegin);

	ethaneTipPosCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_EthaneTankActor::OnTipOverlapBegin);
}

USceneComponent * AVB_EthaneTankActor::GetComponentByIndex(int indexComp)
{
	if (indexComp == 0)
		return GetRootComponent();
	if (indexComp == 1)
		return shapeComp;
	if (indexComp == 2)
		return secondKnobCollisionComp;
	if (indexComp == 3)
		return ethaneTipPosCollisionComp;
	return nullptr;
}

void AVB_EthaneTankActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ATP_MotionController* MotionController = Cast<ATP_MotionController>(OtherActor);
	if (MotionController != nullptr) {
		if (Cast<USphereComponent>(OtherComp) == MotionController->GrabShpere) {
			UE_LOG(LogTemp, Log, TEXT("=======================Code Executed01==========================="));
			if (OverlappedComp == shapeComp) {
				m_isFirstKnobOn = !m_isFirstKnobOn;
			}
			if (OverlappedComp == secondKnobCollisionComp) {
				m_isSecondKnobOn = !m_isSecondKnobOn;
			}
			if (m_isFirstKnobOn && m_isSecondKnobOn && ethaneTip!=nullptr) {
				ethaneTip->ethaneParticle->SetActive(true);
			}
			else {
				ethaneTip->ethaneParticle->SetActive(false);
			}
		}
	}
}

void AVB_EthaneTankActor::OnTipOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_EthaneTipActor* EthaneTipActor = Cast<AVB_EthaneTipActor>(OtherActor);
	if (EthaneTipActor != nullptr) {
		if (ethaneTip == nullptr) {
			UE_LOG(LogTemp, Log, TEXT("=======================Code Executed222222==========================="));
			ethaneTip = EthaneTipActor;
		}
	}
}




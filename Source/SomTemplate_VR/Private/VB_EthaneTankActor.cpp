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
	PrimaryActorTick.bCanEverTick = true;

	bIsFirstKnobTouched = false;
	bIsFirstKnobHold = false;
	bIsSecondKnobTouched = false;
	bIsSecondKnobHold = false;
	
	ConstructorHelpers::FObjectFinder<UMaterial> M_EthaneTankMat(TEXT("Material'/Game/Models/EthaneTank_MainMat.EthaneTank_MainMat'"));
	if (M_EthaneTankMat.Succeeded()) {
		meshComp->SetMaterial(4, M_EthaneTankMat.Object);
	} 

	ethaneTipPosCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("EthaneTipCollision"));
	ethaneTipPosCollisionComp->SetupAttachment(meshComp);
	ethaneTipPosCollisionComp->SetCapsuleSize(1.0f, 1.0f);
	ethaneTipPosCollisionComp->SetRelativeLocation(FVector(-29.33f, 0.75f, 42.8f));

	shapeComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_EthaneTankActor::OnOverlapBegin);
	shapeComp->OnComponentEndOverlap.AddDynamic(this, &AVB_EthaneTankActor::OnOverlapEnd);
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

//Handle tip collides with ethane tank
void AVB_EthaneTankActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ATP_MotionController* MotionController = Cast<ATP_MotionController>(OtherActor);
	if (MotionController != nullptr) {
		if (Cast<USphereComponent>(OtherComp) == MotionController->GrabShpere) {

			bIsFirstKnobTouched = true;
			
			/*if (OverlappedComp == shapeComp) {
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
			}*/
		}
	}
}

void AVB_EthaneTankActor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATP_MotionController* MotionController = Cast<ATP_MotionController>(OtherActor);
	if (MotionController != nullptr) {
			bIsFirstKnobTouched = false;
			bIsFirstKnobHold = false;
	}
}

void AVB_EthaneTankActor::OnTipOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_EthaneTipActor* EthaneTipActor = Cast<AVB_EthaneTipActor>(OtherActor);
	if (EthaneTipActor != nullptr) {
		if (ethaneTip == nullptr) {
			ethaneTip = EthaneTipActor;
		}
	}
}

void AVB_EthaneTankActor::Pickup_Implementation(USceneComponent * AttachTo)
{
	handObjRef = AttachTo;
	m_HandInitialKnobDeltaRotator = handObjRef->GetComponentRotation().Yaw - firstKnob->GetComponentRotation().Yaw;
	bIsFirstKnobHold = true;
}

void AVB_EthaneTankActor::Drop_Implementation()
{
	bIsFirstKnobHold = false;
}

void AVB_EthaneTankActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsFirstKnobTouched && bIsFirstKnobHold) {
		float newSub = handObjRef->GetComponentRotation().Yaw - m_HandInitialKnobDeltaRotator;
		firstKnob->SetWorldRotation(FRotator(firstKnob->GetComponentRotation().Pitch, newSub, firstKnob->GetComponentRotation().Roll));
	}
}






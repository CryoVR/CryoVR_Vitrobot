 // Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_EthaneTankActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"
#include "Materials/Material.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_EthaneTipActor.h"
#include "VB_AirTankActor.h"
#include "VB_WorkstationActor.h"
#include "VB_LevelScriptActor.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"




AVB_EthaneTankActor::AVB_EthaneTankActor() {
	//PrimaryActorTick.bCanEverTick = true;

	bIsFirstKnobTouched = false;
	bIsFirstKnobHold = false;
	bIsSecondKnobTouched = false;
	bIsSecondKnobHold = false;
	m_isTipOn = false;

	//visible bp variabels
	bp_firstknobOn = false;

	static ConstructorHelpers::FObjectFinder<USoundWave> S_1(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/decompress.decompress"));
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

	USoundWave* SoundWave = S_1.Object;
	Hissing_Sound = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest"));
	Hissing_Sound->SetupAttachment(meshComp);
	Hissing_Sound->SetAutoActivate(false);
	Hissing_Sound->SetSound(SoundWave);
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
			if (OverlappedComp == shapeComp) {
				bIsFirstKnobTouched = true;
			}
			if (OverlappedComp == secondKnobCollisionComp) {
				m_isSecondKnobOn = !m_isSecondKnobOn;
				AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
				if (LSA != nullptr)
				{
					if (LSA->GetStatus() == 7)
					{
						Hissing_Sound->Play();
						//LSA->SetStatus(8);
					}
					
					if (LSA->GetStatus() == 9)
					{
						LSA->SetStatus(10);
					}
					
				}
			}
		}

		/*if (m_isFirstKnobOn && m_isSecondKnobOn && ethaneTip != nullptr) {
			ethaneTip->ethaneParticle->SetActive(true);
		}
		else if (!m_isFirstKnobOn || !m_isSecondKnobOn) {
			ethaneTip->ethaneParticle->SetActive(false);
			UE_LOG(LogTemp, Log, TEXT("=======================Tipdown!!!!!==========================="));
		}*/
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


/*
void AVB_EthaneTankActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//check first knob
	if (bp_firstknobOn || bIsFirstKnobTouched && bIsFirstKnobHold) {
			//float newSub = handObjRef->GetComponentRotation().Yaw - m_HandInitialKnobDeltaRotator;
			//newSub = FMath::Clamp(newSub, -50.0f, 30.0f);
			//firstKnob->SetWorldRotation(FRotator(firstKnob->GetComponentRotation().Pitch, newSub, firstKnob->GetComponentRotation().Roll));
			if (firstKnob->GetComponentRotation().Yaw <= -50.0f) {
				m_isFirstKnobOn = true;
				//UE_LOG(LogTemp, Log, TEXT("=======================firstknob_ON==========================="));
				AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
				if (LSA != nullptr)
				{
					if (LSA->GetStatus() == 4)
					{
						LSA->SetStatus(5);
					}
				}
			}
			if (firstKnob->GetComponentRotation().Yaw >= 30.0f) {
				m_isFirstKnobOn = false;
				//UE_LOG(LogTemp, Log, TEXT("=======================firstknob_OFF==========================="));
				AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
				if (LSA != nullptr)
				{
					if (LSA->GetStatus() == 10)
					{
						LSA->SetStatus(11);
					}
				}
			}
	}

	//meter on
	if (m_isFirstKnobOn) {
		if (firstPointer->GetComponentRotation().Yaw < 40.0f) {
			firstPointer->AddLocalRotation(FRotator(-1.5f, 0.0f, 0.0f));
			secondPointer->AddLocalRotation(FRotator(-1.5f, 0.0f, 0.0f));
		}
	}

	//meter off
	if (!m_isFirstKnobOn) {
		if (firstPointer->GetComponentRotation().Yaw > -115.8f) {
			firstPointer->AddLocalRotation(FRotator(1.5f, 0.0f, 0.0f));
		}
		if (secondPointer->GetComponentRotation().Yaw > -158.5f) {
			secondPointer->AddLocalRotation(FRotator(1.5f, 0.0f, 0.0f));
		}
	}	


	if (m_isFirstKnobOn && m_isSecondKnobOn && ethaneTip != nullptr) {
		ethaneTip->ethaneParticle->SetActive(true);
		m_isTipOn = true;
	}
	else if ((!m_isFirstKnobOn || !m_isSecondKnobOn) && ethaneTip != nullptr) {
		ethaneTip->ethaneParticle->SetActive(false);
		//UE_LOG(LogTemp, Log, TEXT("=======================Tipdown!!!!!==========================="));
	}
}

*/






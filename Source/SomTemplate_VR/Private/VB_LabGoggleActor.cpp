// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_LabGoggleActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_LevelScriptActor.h"
#include "VirtualReality/TP_MotionController.h"
#include "VirtualReality/TP_VirtualRealityPawn_Motion.h"
#include "Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"



AVB_LabGoggleActor::AVB_LabGoggleActor()
{
	static ConstructorHelpers::FObjectFinder<USoundWave> S_Success(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/FinishTask.FinishTask"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Goggle(TEXT("StaticMesh'/Game/Test_Geometry/glass.glass'"));

	// sound
	USoundWave* SoundWaveSuccess = S_Success.Object;
	SSoundSuccess = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTestSuccess"));
	SSoundSuccess->SetupAttachment(PickupMesh);
	SSoundSuccess->SetAutoActivate(false);
	SSoundSuccess->SetSound(SoundWaveSuccess);

	if (SM_Goggle.Succeeded())
	{
		UStaticMesh* Asset = SM_Goggle.Object;
		PickupMesh->SetStaticMesh(Asset);
		//BoxComp->SetupAttachment(PickupMesh);

	}
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_LabGoggleActor::OnOverlapBegin);
}



void AVB_LabGoggleActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	if (Cast<ATP_VirtualRealityPawn_Motion>(OtherActor) != nullptr)
	{
		Is_Weard = true;
		if (PickupMesh->IsVisible() == true) {
			SSoundSuccess->Play();
			PickupMesh->SetVisibility(false);
		}
		PickupMesh->SetGenerateOverlapEvents(false);
		BoxComp->SetGenerateOverlapEvents(false);
	}
}

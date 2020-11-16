// Copyright (c) 2017-2020 CryoVR, All Rights Reserved.


#include "VB_CleanLiquidSampleRack.h"
#include "Public/Engine.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_LevelScriptActor.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_CleanTableCompActor.h"

AVB_CleanLiquidSampleRack::AVB_CleanLiquidSampleRack()
{
	bIsOnTable = false;

	
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CleanLiquidSampleRackComp"));
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//boxComp->SetRelativeLocation(FVector(-35.17f, -16.99f, 5.26f));
	boxComp->SetRelativeScale3D(FVector(0.375f, 1.0f, 0.1825f));
	
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CleanLiquidSampleRack(TEXT("StaticMesh'/Game/Models/SampleRack.SampleRack'"));
	if (SM_CleanLiquidSampleRack.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_CleanLiquidSampleRack.Object);
		boxComp->SetupAttachment(PickupMesh);
	}


	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanLiquidSampleRack::OnOverlapBegin);
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanLiquidSampleRack::OnOverlapBegin);
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_CleanLiquidSampleRack::OnHandOverlapBegin);

}

void AVB_CleanLiquidSampleRack::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVB_CleanTableCompActor* CleanTableCompActor = Cast<AVB_CleanTableCompActor>(OtherActor);
	if (CleanTableCompActor != nullptr) {
		bIsOnTable = true;
	}
}

void AVB_CleanLiquidSampleRack::OnHandOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("LiquidSampleRack_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.162f, 1.12f}, Cast<ATP_MotionController>(OtherActor));
	}
}
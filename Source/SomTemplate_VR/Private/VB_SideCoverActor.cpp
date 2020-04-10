// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_SideCoverActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VB_StaticActor.h"
#include "VB_LevelScriptActor.h"
#include "Materials/MaterialInstanceConstant.h"
#include "VirtualReality/TP_MotionController.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"






AVB_SideCoverActor::AVB_SideCoverActor() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SideCoverActor(TEXT("StaticMesh'/Game/Test_Geometry/Side_Cover.Side_Cover'"));

	isCoverTouched = false;

	if (SM_SideCoverActor.Succeeded()) {
		meshComp->SetStaticMesh(SM_SideCoverActor.Object);
	}

	
	meshComp->SetGenerateOverlapEvents(false);
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	meshComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	meshComp->SetRelativeLocationAndRotation(FVector(61.08f, 13.10f, 161.53f), FRotator(0.0f, 270.0f, 89.99f));

	shapeComp->SetRelativeScale3D(FVector(0.03f, 0.03f, 0.03f));
	shapeComp->SetupAttachment(meshComp);
	shapeComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_SideCoverActor::OnOverlapBegin);


}

void AVB_SideCoverActor::setcoverVisible()
{
	meshComp->SetVisibility(true);
}

void AVB_SideCoverActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ATP_MotionController* MotionController = Cast<ATP_MotionController>(OtherActor);
	if (MotionController != nullptr) {
		if (Cast<USphereComponent>(OtherComp) == MotionController->GrabShpere) {
			if (OverlappedComp == shapeComp) {
				isCoverTouched = true;
				meshComp->SetVisibility(false);
			}
			if (isCoverTouched == true) {
				GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &AVB_SideCoverActor::setcoverVisible, 5.0f, false);
			}
			AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
			if (LSA != NULL) {
				if (LSA->GetStatus() == 18) {
					LSA->SetStatus(19);
				}
			}
		}
	}
}

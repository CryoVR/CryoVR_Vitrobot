// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PenActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_LevelScriptActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Public/Engine.h"


AVB_PenActor::AVB_PenActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Main(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Stylus.Stylus'"));
	
		if (SM_Main.Succeeded()) {
			PickupMesh->SetStaticMesh(SM_Main.Object);
		}
		PickupMesh->SetRelativeScale3D(FVector(1.0f));
	
		Pointer_Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Stylus_Collider"));
		//Pointer_Collider->SetVisibility(false);
		//Pointer_Collider->SetRelativeLocation(FVector(0.0f, 0.0f, -10.92f));
		//Pointer_Collider->SetRelativeScale3D(FVector(1.0f));
		Pointer_Collider->SetCapsuleSize(6.0f, 0.5f);
		Pointer_Collider->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
		Pointer_Collider->SetupAttachment(PickupMesh);
		Pointer_Collider->OnComponentBeginOverlap.AddDynamic(this, &AVB_PenActor::OnOverlapBegin);
}

void AVB_PenActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor))
	{
		UpdateHandGuestureFunc(true, FName("Pen_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.8f, 0.5f}, Cast<ATP_MotionController>(OtherActor));
	}
}

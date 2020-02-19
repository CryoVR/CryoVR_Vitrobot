// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_GridDewarActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_LevelScriptActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


AVB_GridDewarActor::AVB_GridDewarActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_MainMesh(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Grid_Dewar.Grid_Dewar'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Cap(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Grid_Dewar_Cap.Grid_Dewar_Cap'"));

	if (SM_MainMesh.Succeeded()) {
		meshComp->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		meshComp->SetStaticMesh(SM_MainMesh.Object);
		meshComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		shapeComp->DestroyComponent();
	}
	GridDewar_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("GridDewar_Collider"));
	GridDewar_Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	GridDewar_Collider->SetupAttachment(meshComp);
	GridDewar_Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	GridDewar_Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 69.5f));
	Cast<UBoxComponent>(GridDewar_Collider)->SetBoxExtent(FVector(4.0f, 4.0f, 1.5f));

	GridDewarCap = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GirdDewar_Cap"));
	GridDewarCap->SetupAttachment(meshComp);
	GridDewarCap->SetGenerateOverlapEvents(true);
	GridDewarCap->SetVisibility(true);
	GridDewarCap->SetRelativeLocation(FVector(0.0f, 16.1612015f, 65.405426f));
	if (SM_Cap.Succeeded()) {
		GridDewarCap->SetStaticMesh(SM_Cap.Object);
	}
	GridDewarCap_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("GridDewarCap_Collider"));
	GridDewarCap_Collider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GridDewarCap_Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GridDewarCap_Collider->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	GridDewarCap_Collider->SetupAttachment(GridDewarCap);
	GridDewarCap_Collider->SetRelativeLocation(FVector(0.0f, -15.8f, 2.95f));
	Cast<UBoxComponent>(GridDewarCap_Collider)->SetBoxExtent(FVector(15.0f, 15.0f, 3.0f));
}

void AVB_GridDewarActor::OnCapOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor) != nullptr)
	{	if(GridDewarCap->GetComponentRotation().Pitch < 50.0f)
		{
			GridDewarCap->SetRelativeRotation(FRotator(140.0f, 0.0f, 0.0f));
		}
		else
		{
			GridDewarCap->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
		
	}
}

void AVB_GridDewarActor::SetIsTouchable(bool B)
{
	IsTouchable = B;
}

bool AVB_GridDewarActor::GetIsTouchable()
{
	return IsTouchable;
}


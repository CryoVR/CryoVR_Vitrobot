// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_FreezingDewarActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "VB_DewarActor.h"
#include "VB_LevelScriptActor.h"
#include "VB_GridBoxTweezerActor.h"

AVB_FreezingDewarActor::AVB_FreezingDewarActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_FDewar(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/FreezeDewar.FreezeDewar'"));

	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("FreezingDewarComp"));
	capsuleComp->SetGenerateOverlapEvents(true);
	capsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	capsuleComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	capsuleComp->SetCapsuleSize(2.0f, 3.0f);
	capsuleComp->SetRelativeLocation(FVector(0.0f, 0.0f, 39.90f));
	capsuleComp->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.15f));
	capsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_FreezingDewarActor::OnDewarOverlapBegin);

	if (SM_FDewar.Succeeded()) 
	{
		meshComp->SetStaticMesh(SM_FDewar.Object);
		capsuleComp->SetupAttachment(meshComp);
	}

	shapeComp->DestroyComponent();
	shapeComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("FDShapeComp"));
	shapeComp->SetGenerateOverlapEvents(true);
	shapeComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	shapeComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Cast<UCapsuleComponent>(shapeComp)->SetCapsuleSize(22.0f, 44.0f);
	shapeComp->SetRelativeLocation(FVector(0.0f, 0.0f, 14.90f));
	shapeComp->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.25f));
	shapeComp->SetupAttachment(meshComp);
	shapeComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_FreezingDewarActor::OnGBTweezerOverlapBegin);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> Dewar_Effect(TEXT("ParticleSystem'/Game/Particles/WaterSplash_P.WaterSplash_P'"));
	if (Dewar_Effect.Succeeded())
	{
		P_Frozen = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FrozenEffect"));
		P_Frozen->SetTemplate(Dewar_Effect.Object);
		P_Frozen->SetVisibility(false);
		P_Frozen->SetupAttachment(meshComp);
		P_Frozen->SetRelativeLocation(FVector(0.0f, 0.0f, 43.85f));
		P_Frozen->SetRelativeScale3D(FVector(2.5f, 2.5f, 1.0f));
	}


}

void AVB_FreezingDewarActor::OnDewarOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{	
	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	AVB_DewarActor* DewarActor = Cast<AVB_DewarActor>(OtherActor);
	if (DewarActor != nullptr)
	{
		P_Frozen->SetVisibility(true);
		if (LSA->GetStatus() == 29)
		{
			LSA->SetStatus(30);
		}
	}
}

void AVB_FreezingDewarActor::OnGBTweezerOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_GridBoxTweezerActor* GBTweezerActor = Cast<AVB_GridBoxTweezerActor>(OtherActor);
	if (GBTweezerActor != nullptr)
	{
		GBTweezerActor->m_isTweezerFrozen = true;
	}
}

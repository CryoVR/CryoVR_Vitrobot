// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_WorkstationActor.h"
#include "Public/Engine.h"
#include "Components/Boxcomponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VB_DewarActor.h"
#include "VB_VitrobotActor.h"
#include "VB_EthaneTankActor.h"
#include "VB_EthaneTipActor.h"
#include "VB_VitrobotActor.h"
#include "VirtualReality/TP_MotionController.h"

AVB_WorkstationActor::AVB_WorkstationActor() 
{
	PrimaryActorTick.bCanEverTick = true;
	
	isTipTouched = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Workstation.Workstation'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_P0(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Workstation_P0.Workstation_P0'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_P1(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Workstation_P1.Workstation_P1'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_P2(TEXT("StaticMesh'/Game/Test_Geometry/Test_Textures/Workstation_P2.Workstation_P2'"));
	if (SM_Pickup.Succeeded())
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);
	}

	Workstation_P0 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Workstation_P0"));
	//Workstation_P0->SetupAttachment(PickupMesh);
	Workstation_P0->SetGenerateOverlapEvents(false);
	Workstation_P0->SetSimulatePhysics(false);
	Workstation_P0->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Workstation_P0->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Workstation_P0->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	Workstation_P0->SetVisibility(true);
	Workstation_P0->SetRelativeLocation(FVector(-0.094f, -0.131f, 0.806f));
	if (SM_P0.Succeeded()) {
		Workstation_P0->SetStaticMesh(SM_P0.Object);
	}

	Workstation_P1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Workstation_P1"));
	//Workstation_P1->SetupAttachment(PickupMesh);
	Workstation_P1->SetGenerateOverlapEvents(false);
	Workstation_P1->SetSimulatePhysics(false);
	Workstation_P1->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Workstation_P1->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Workstation_P1->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	Workstation_P1->SetVisibility(true);
	Workstation_P1->SetRelativeLocation(FVector(0.176f, -0.007f, 1.622f));
	if (SM_P1.Succeeded()) {
		Workstation_P1->SetStaticMesh(SM_P1.Object);
	}

	Workstation_P2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Workstation_P2"));
	//Workstation_P2->SetupAttachment(PickupMesh);
	Workstation_P2->SetGenerateOverlapEvents(false);
	Workstation_P2->SetSimulatePhysics(false);
	Workstation_P2->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Workstation_P2->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Workstation_P2->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	Workstation_P2->SetVisibility(true);
	Workstation_P2->SetRelativeLocation(FVector(-0.04f, 0.0f, 3.582f));
	if (SM_P2.Succeeded()) {
		Workstation_P2->SetStaticMesh(SM_P2.Object);
	}
	

	PickupMesh->SetGenerateOverlapEvents(true);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetGenerateOverlapEvents(true); 
	BoxComp->SetupAttachment(PickupMesh);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_WorkstationActor::OnOverlapBegin);
	BoxComp->SetRelativeLocation(FVector(0.0f, 0.0f, 3.26f));
	BoxComp->SetRelativeScale3D(FVector(0.22f, 0.22f, 0.11f));

	Water_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WaterComp"));
	Water_Mesh->SetupAttachment(PickupMesh);
	Water_Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 5.8415222f));//Least 1.39f
	Water_Mesh->SetRelativeScale3D(FVector(0.16f, 0.16f, 0.01f));
	Water_Mesh->SetVisibility(false);


	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_Effect(TEXT("ParticleSystem'/Game/Test_Geometry/Test_Particle/P_Steam_Lit.P_Steam_Lit'"));
	if (P_Effect.Succeeded())
	{
		FrozenFX = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FrozenEffect"));
		FrozenFX->SetTemplate(P_Effect.Object);
		FrozenFX->SetVisibility(false);
		FrozenFX->SetupAttachment(PickupMesh);
	}

	FrozenFX->SetRelativeLocation(FVector(0.0f, 0.0f, 7.0f));
}

void AVB_WorkstationActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	if (Cast<AVB_DewarActor>(OtherActor) != nullptr)
	{
		FrozenFX->SetVisibility(true);
		Water_Mesh->SetVisibility(true);
	}

	AVB_VitrobotActor* VitrobotActor = Cast<AVB_VitrobotActor>(OtherActor);
	if (VitrobotActor != nullptr) {
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(VitrobotActor->WorkstationHolder, AttachRules, FName("workstationSocket1"));
	}

	//Hand gesture setting
	if (Cast<ATP_MotionController>(OtherActor)) {
		UpdateHandGuestureFunc(true, FName("WorkStation_Socket"), EAttachmentRule::SnapToTarget, FVector(1.0f), TArray<float> {0.25f, 1.0f}, Cast<ATP_MotionController>(OtherActor));
	}

	//ethane tip add
	AVB_EthaneTipActor* ethaneTip = Cast<AVB_EthaneTipActor>(OtherActor);
	//AVB_EthaneTankActor* ethaneTank = Cast<AVB_EthaneTankActor>(OtherActor);
	if (ethaneTip != nullptr) {
		if (OtherComp == ethaneTip->ethaneTipCollisionComp) {
			//GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &AVB_WorkstationActor::setFrozVisible, 5.0f, false);
			//FrozenFX->SetVisibility(false);
			isTipTouched = true;
		}
	}

	/*if (Status == 0)
	{
		TempLocation = PickupMesh->GetComponentLocation();
		Status = 1;
	}
	else if (Status != 0)
	{
		FVector L_Main = PickupMesh->GetComponentLocation();
		DeltaLocation = L_Main - TempLocation;
		Workstation_P0->AddLocalOffset(DeltaLocation);
	}*/
	
}

void AVB_WorkstationActor::setFrozVisible()
{
	FrozenFX->SetVisibility(false);
}


void AVB_WorkstationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bool m_IsVisable = Water_Mesh->IsVisible();
	if (Water_Mesh->GetComponentLocation().Z > 119.4831085f && m_IsVisable) {
		Water_Mesh->AddWorldOffset(FVector(0.0f, 0.0f, -0.005f));
	}
	
}


 
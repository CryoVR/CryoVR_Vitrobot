// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_VitrobotActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "VirtualReality/TP_MotionController.h"


AVB_VitrobotActor::AVB_VitrobotActor() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_MainMesh(TEXT("StaticMesh'/Game/Test_Geometry/Main_Machine_1_3size.Main_Machine_1_3size'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_WorkstationHolder(TEXT("StaticMesh'/Game/Test_Geometry/Workstation_Holder_1_3size.Workstation_Holder_1_3size'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_InnerHolder(TEXT("StaticMesh'/Game/Test_Geometry/Inner_Holder_1_3size.Inner_Holder_1_3size'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BottomCover(TEXT("StaticMesh'/Game/Test_Geometry/Cover_Bottom_1_3size.Cover_Bottom_1_3size'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_LEDCover(TEXT("StaticMesh'/Game/Test_Geometry/LED_Cover.LED_Cover'"));

	if (SM_MainMesh.Succeeded()) {
		meshComp->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		meshComp->SetStaticMesh(SM_MainMesh.Object);
		shapeComp->DestroyComponent();
	}

	//#1 WorkStation_Holder and its collider
	WorkstationHolder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Workstation_Holder"));
	WorkstationHolder->SetupAttachment(meshComp);
	WorkstationHolder->SetGenerateOverlapEvents(true);
	WorkstationHolder->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	WorkstationHolder->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WorkstationHolder->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	WorkstationHolder->SetVisibility(true);
	WorkstationHolder->SetRelativeLocation(FVector(0.0f, -3.17f, 6.6f));

	if (SM_WorkstationHolder.Succeeded()) {
		WorkstationHolder->SetStaticMesh(SM_WorkstationHolder.Object);
	}
	WorkstationHolder_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("test"));
	WorkstationHolder_Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WorkstationHolder_Collider->SetupAttachment(WorkstationHolder);
	WorkstationHolder_Collider->SetRelativeLocation(FVector(0.0f, -15.95f, 0.8f));
	Cast<UBoxComponent>(WorkstationHolder_Collider)->SetBoxExtent(FVector(8.0f, 8.0f, 1.3f));
	//For future workstation binding
	//rkstationHolder_Collider->SetCollisionResponseToChannel(ECollisionResponse::ECR_Ignore);

	//#2 InnerHolder
	InnerHolder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner_Holder"));
	InnerHolder->SetupAttachment(meshComp);
	InnerHolder->SetGenerateOverlapEvents(true);
	InnerHolder->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InnerHolder->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	InnerHolder->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	InnerHolder->SetVisibility(true);
	InnerHolder->SetRelativeLocation(FVector(0.0f, -15.0f, 57.2f));
	if (SM_InnerHolder.Succeeded()) {
		InnerHolder->SetStaticMesh(SM_InnerHolder.Object);
	}

	//#3 BottomCover
	BottomCover = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottom_Cover"));
	BottomCover->SetupAttachment(meshComp);
	BottomCover->SetGenerateOverlapEvents(true);
	BottomCover->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BottomCover->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BottomCover->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	BottomCover->SetVisibility(true);
	BottomCover->SetRelativeLocation(FVector(12.9f, -26.6f, 49.3f));
	BottomCover->SetRelativeRotation(FRotator(0.0f, 45.0f, 0.0f));
	if (SM_BottomCover.Succeeded()) {
		BottomCover->SetStaticMesh(SM_BottomCover.Object);
	}
	BottomCover_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Bottom_Cover_Collider"));
	BottomCover_Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	//BottomCover_Collider->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	BottomCover_Collider->SetupAttachment(BottomCover);
	BottomCover_Collider->SetRelativeLocation(FVector(-25.0f, -0.85f, 1.3f));
	Cast<UBoxComponent>(BottomCover_Collider)->SetBoxExtent(FVector(1.3f, 1.3f, 12.7f));
	BottomCover_Collider->OnComponentBeginOverlap.AddDynamic(this, &AVB_VitrobotActor::OnOverlapBegin);

	//#4 LEDCover
	LEDCover = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LED_Cover"));
	LEDCover->SetupAttachment(meshComp);
	LEDCover->SetGenerateOverlapEvents(true);
	LEDCover->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	LEDCover->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	LEDCover->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	LEDCover->SetVisibility(true);
	LEDCover->SetRelativeLocation(FVector(12.9f, -26.6f, 74.5f));
	if (SM_LEDCover.Succeeded()) {
		LEDCover->SetStaticMesh(SM_LEDCover.Object);
	}
	TestButton_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("TestButton_Collider"));
	TestButton_Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TestButton_Collider->SetupAttachment(LEDCover);
	TestButton_Collider->SetRelativeLocation(FVector(-13.5f, -1.6f, -0.6f));
	Cast<UBoxComponent>(TestButton_Collider)->SetBoxExtent(FVector(3.0f, 1.0f, 3.0f));
	TestButton_Collider->SetHiddenInGame(false);
}

//Set if the InnerHolder is interactable.
void AVB_VitrobotActor::ActiveInnerHolder(bool bIs)
{
	if (bIsInteractable) 
	{
		InnerHolder->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Ignore);
	}
}

void AVB_VitrobotActor::DeactiveInnerHolder(bool bIs)
{
	if (!bIsInteractable)
	{
		InnerHolder->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	}
}



void AVB_VitrobotActor::SetInteractableByRotation(UStaticMeshComponent* SM_Mesh)
{
	FRotator TempRotator = SM_Mesh->GetComponentRotation();
	float TempYaw = TempRotator.Yaw;
}

void AVB_VitrobotActor::MoveWorkstationHolder(float F)
{
	float addz = 1.0f;
	float addz = addz * F;
	InnerHolder->AddRelativeLocation(FVector(0.0f, 0.0f, addz));
}

void AVB_VitrobotActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ATP_MotionController>(OtherActor) != nullptr)	
	{	
		if (OverlappedComp = BottomCover_Collider)
		{
			if (BottomCover_Collider->GetComponentRotation().Yaw >= 60.0f)
			{
				InnerHolder->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
			}
			else if (BottomCover_Collider->GetComponentRotation().Yaw >= 0.0f && BottomCover_Collider->GetComponentRotation().Yaw < 60.0f)
			{
				InnerHolder->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Ignore);
			}
		}

		if (OverlappedComp = TestButton_Collider)
		{
			if (bIsButtonOn)
			{
				bIsButtonOn = false;
			}
			else
			{
				bIsButtonOn = true;
			}
		}
	}
}

void AVB_VitrobotActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsButtonOn)
	{	//6.6->27.6
		if (WorkstationHolder->GetComponentLocation().Z < 7.0f)
		{
			MoveWorkstationHolder(1.0f);
		}
		else if (WorkstationHolder->GetComponentLocation().Z > 26.0f)
		{
			MoveWorkstationHolder(-1.0f);
		}


	}

}
// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_Pipette_Hand.h"
#include "Public/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"


AVB_Pipette_Hand::AVB_Pipette_Hand()
{	
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/Models/Pipet.Pipet'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM_HandMesh(TEXT("SkeletalMesh'/Game/VirtualReality/Mannequin/Character/Mesh/StylizedManHand_Right.StylizedManHand_Right'"));
	static ConstructorHelpers::FObjectFinder<UAnimationAsset> AA_Anim(TEXT("AnimAsset'/Game/VirtualReality/Mannequin/Animations/MannequinHand_Right_GrabPipet.MannequinHand_Right_GrabPipet'"));

	if (SM_Pickup.Succeeded())
	{
		UStaticMesh* Asset = SM_Pickup.Object;
		PickupMesh->SetStaticMesh(Asset);
		PickupMesh->SetSimulatePhysics(false);
		PickupMesh->SetRelativeScale3D(FVector(1.35f));
	}

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hand_Mesh"));
	MeshComp->SetupAttachment(PickupMesh);
	MeshComp->SetGenerateOverlapEvents(false);
	MeshComp->SetSimulatePhysics(false);
	MeshComp->SetVisibility(true);
	MeshComp->SetRelativeLocation(FVector(-9.3367119f, 1.3254448f, 0.8060031f));
	MeshComp->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
	MeshComp->SetRelativeScale3D(FVector(0.8f));
	MeshComp->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	UAnimationAsset *Anim = AA_Anim.Object;
	if (SM_HandMesh.Succeeded()) {
		MeshComp->SetSkeletalMesh(SM_HandMesh.Object);
		MeshComp->SetAnimation(Anim);
	}

	PressureValue = 0.2;

}

void AVB_Pipette_Hand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//This is the Rotation value from the Actor
	FRotator RotateValue = MeshComp->GetComponentRotation();

	//Try to set the pressure value here, the default value should be between 0.0 and 1.0;
	PressureValue += 0.0001;
	
}

// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
// SomWorks :D // MIT LICENSE // Epic VR Template Convert C++ Open Source Project.

#include "TP_PickupCube_NVR.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceConstant.h"
#include "VirtualReality/TP_MotionController.h"

// Sets default values
ATP_PickupCube::ATP_PickupCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pickup(TEXT("StaticMesh'/Game/VirtualReality/Meshes/1x1_cube.1x1_cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MI_SmallCubes(TEXT("MaterialInstanceConstant'/Game/VirtualReality/Materials/MI_SmallCubes.MI_SmallCubes'"));
	
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootMesh"));
		
	//RootComponent = PickupMesh;
	SetRootComponent(PickupMesh);
	PickupMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	PickupMesh->SetSimulatePhysics(false);
	PickupMesh->SetNotifyRigidBodyCollision(true);
	PickupMesh->SetGenerateOverlapEvents(true);
	PickupMesh->SetCollisionProfileName("PhysicsActor");

	if (SM_Pickup.Succeeded())
	{
		PickupMesh->SetStaticMesh(SM_Pickup.Object);
		if (MI_SmallCubes.Succeeded())
		{
			PickupMesh->SetMaterial(0, MI_SmallCubes.Object);
		}
	}

	m_isDefinedPick = false;
	m_originalScale3D = FVector(1.0f);
	m_attachToSocketRule = EAttachmentRule::KeepWorld;
	m_attachSocketName = FName("");

}

// Called when the game starts or when spawned
void ATP_PickupCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP_PickupCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Update hand guesture to specific state, called by collision event
void ATP_PickupCube::UpdateHandGuestureFunc(bool isDefinedPick, const FName & attachSocketName, const EAttachmentRule & attachToSocketRule, const FVector & V, const TArray<float>& handGuesture, ATP_MotionController* motionController)
{
	if (motionController && !motionController->m_isGrab) {
		m_isDefinedPick = isDefinedPick;
		m_attachSocketName = attachSocketName;
		m_attachToSocketRule = attachToSocketRule;
		m_originalScale3D = V;
		motionController->HandGestureInput = handGuesture;
	}
	/*FString AAA = AttachTo->GetFName().ToString();
	const TCHAR* BBB = *AAA;*/
	//UE_LOG(LogTemp, Log, TEXT("Attach To Name =================================================== %s"), BBB)
}

//Reset hand guesture to default state. Called by drop interface
void ATP_PickupCube::ResetHandGuestureFunc()
{
	m_isDefinedPick = false;
	m_attachSocketName = "";
	m_attachToSocketRule = EAttachmentRule::KeepWorld;
	m_originalScale3D = FVector(1.0f);
	if (m_ourMotionController) m_ourMotionController->HandGestureInput = { 2.0f, 1.0f }; // Hand guesture: default is 2.0 and 1.0
}

void ATP_PickupCube::Pickup_Implementation(USceneComponent* AttachTo)
{
	PickupMesh->SetSimulatePhysics(false);
	FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::KeepWorld, false);
	GetRootComponent()->AttachToComponent(AttachTo->GetChildComponent(0), AttachmentTransformRules);
}

void ATP_PickupCube::Drop_Implementation()
{
	//UE_LOG(LogTemp, Log, TEXT("Drop Execution =================================================== "))
	PickupMesh->SetSimulatePhysics(true);
	FDetachmentTransformRules DetatchmentTransformRules(EDetachmentRule::KeepWorld, false);
	DetachFromActor(DetatchmentTransformRules);
	
}
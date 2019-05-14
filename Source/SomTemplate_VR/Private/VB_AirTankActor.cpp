// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
#include "VB_AirTankActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

AVB_AirTankActor::AVB_AirTankActor() {
	PrimaryActorTick.bCanEverTick = true;

	isFirstKnobOn = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_AirtankMesh(TEXT("StaticMesh'/Game/Models/EthaneTank.EthaneTank'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_FirstKnobMesh(TEXT("StaticMesh'/Game/Models/EthaneKnob.EthaneKnob'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SecondKnobMesh(TEXT("StaticMesh'/Game/Models/EthaneKnob_02.EthaneKnob_02'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Pointer(TEXT("StaticMesh'/Game/Models/EthanePointer.EthanePointer'"));

	if (SM_AirtankMesh.Succeeded()) {
		meshComp->SetStaticMesh(SM_AirtankMesh.Object);
	}

	firstKnob = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstKnobComp"));
	firstKnob->SetGenerateOverlapEvents(false);
	firstKnob->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	firstKnob->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	firstKnob->SetupAttachment(meshComp);
	firstKnob->SetRelativeLocation(FVector(0.0f, 0.0f, 46.0f));
	if (SM_FirstKnobMesh.Succeeded()) {
		firstKnob->SetStaticMesh(SM_FirstKnobMesh.Object);
	}

	//We reuse shapeComp and bind it to our first knob
	shapeComp->DestroyComponent();
	shapeComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("MainCollisionBox"));
	shapeComp->SetGenerateOverlapEvents(true);
	shapeComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	shapeComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Cast<UCapsuleComponent>(shapeComp)->SetCapsuleSize(3.5f, 3.5f);
	shapeComp->SetupAttachment(firstKnob);
	shapeComp->SetRelativeLocation(FVector(0.0f, 0.0f, 2.0f));

	firstPointer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pointer_01"));
	firstPointer->SetGenerateOverlapEvents(false);
	firstPointer->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	firstPointer->SetupAttachment(meshComp);
	//FQuat newPointerQuat = FQuat(FRotator(-127.524f, 55.0f, -133.1f));
	//FQuat newPointerQuat = FQuat(FRotator(232.476f, 55.0f, 226.9f));
	//FQuat newPointerQuat = FQuat(FRotator(55.0f, -133.1f, -127.52f));
	firstPointer->AddLocalRotation(FRotator(55.0f, -133.1f, -127.52f));
	//FRotator test = firstPointer->GetComponentRotation();
	//FString AAA = test.ToString();
	//const TCHAR* BBB = *AAA;
	//UE_LOG(LogTemp, Log, TEXT("Test =================================================== %s"), BBB);
	//firstPointer->SetRelativeRotation(newPointerQuat);
	//firstPointer->AddLocalRotation(FRotator(232.476f, 55.0f, 226.9f));
	firstPointer->SetRelativeLocation(FVector(-12.653f, -4.8575f, 54.3f));
	

	secondPointer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pointer_02"));
	secondPointer->SetGenerateOverlapEvents(false);
	secondPointer->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	secondPointer->SetupAttachment(meshComp);

	if (SM_Pointer.Succeeded()) {
		firstPointer->SetStaticMesh(SM_Pointer.Object);
		secondPointer->SetStaticMesh(SM_Pointer.Object);
	}

}

void AVB_AirTankActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
 
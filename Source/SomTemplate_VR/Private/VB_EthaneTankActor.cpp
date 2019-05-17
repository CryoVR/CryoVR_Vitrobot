// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_EthaneTankActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "ConstructorHelpers.h"
#include "Materials/Material.h"


AVB_EthaneTankActor::AVB_EthaneTankActor() {
	PrimaryActorTick.bCanEverTick = false;

	ConstructorHelpers::FObjectFinder<UMaterial> M_EthaneTankMat(TEXT("Material'/Game/Models/EthaneTank_MainMat.EthaneTank_MainMat'"));
	if (M_EthaneTankMat.Succeeded()) {
		meshComp->SetMaterial(4, M_EthaneTankMat.Object);
	}

	ethaneTipPosCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("EthaneTipCollision"));
	ethaneTipPosCollisionComp->SetupAttachment(meshComp);
	ethaneTipPosCollisionComp->SetCapsuleSize(1.0f, 1.0f);
	ethaneTipPosCollisionComp->SetRelativeLocation(FVector(-29.33f, 0.75f, 42.8f));

}

USceneComponent * AVB_EthaneTankActor::GetComponentByIndex(int indexComp)
{
	if (indexComp == 0)
		return GetRootComponent();
	if (indexComp == 1)
		return shapeComp;
	if (indexComp == 2)
		return secondKnobCollisionComp;
	if (indexComp == 3)
		return ethaneTipPosCollisionComp;
	return nullptr;
}

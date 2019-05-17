// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019
#include "VB_DynamicActor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"


AVB_DynamicActor::AVB_DynamicActor() {
	m_isPickable = true;
	PickupMesh->SetSimulatePhysics(false);
}

void AVB_DynamicActor::Pickup_Implementation(USceneComponent * AttachTo)
{
	PickupMesh->SetSimulatePhysics(false);
	if (m_isPickable) {
		FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(AttachTo, AttachmentTransformRules);
	}
}

void AVB_DynamicActor::BeginPlay()
{
	Super::BeginPlay();
	m_OriginalTransform = GetActorTransform();
}

void AVB_DynamicActor::setPickable(bool newPickable)
{
	m_isPickable = newPickable;
}

bool AVB_DynamicActor::getPickable()
{
	return m_isPickable;
}

void AVB_DynamicActor::OnHitGround(float resetTransformTimer)
{
	GetWorldTimerManager().ClearTimer(timeHandler);
	GetWorldTimerManager().SetTimer(timeHandler, this, &AVB_DynamicActor::ResetActorState, resetTransformTimer);
}

void AVB_DynamicActor::ResetActorState()
{
	SetActorTransform(m_OriginalTransform);
	PickupMesh->SetSimulatePhysics(false);
}

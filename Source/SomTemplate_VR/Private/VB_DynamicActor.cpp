// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "VB_DynamicActor.h"
#include "Components/StaticMeshComponent.h"

AVB_DynamicActor::AVB_DynamicActor() {
	m_isPickable = true;
}

void AVB_DynamicActor::Pickup_Implementation(USceneComponent * AttachTo)
{
	PickupMesh->SetSimulatePhysics(false);
	if (m_isPickable) {
		FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::KeepWorld, false);
		GetRootComponent()->AttachToComponent(AttachTo, AttachmentTransformRules);
	}
}

void AVB_DynamicActor::setPickable(bool newPickable)
{
	m_isPickable = newPickable;
}

bool AVB_DynamicActor::getPickable()
{
	return m_isPickable;
}

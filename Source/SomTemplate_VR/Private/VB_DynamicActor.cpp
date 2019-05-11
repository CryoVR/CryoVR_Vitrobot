// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "VB_DynamicActor.h"
#include "Components/StaticMeshComponent.h"

AVB_DynamicActor::AVB_DynamicActor() {
	m_isPickable = true;

}

void AVB_DynamicActor::Pickup_Implementation(USceneComponent * AttachTo)
{
	if (m_isPickable) {
		PickupMesh->SetSimulatePhysics(false);
	}
}

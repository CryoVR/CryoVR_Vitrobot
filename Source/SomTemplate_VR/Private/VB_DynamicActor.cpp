// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019
#include "VB_DynamicActor.h"
#include "Components/StaticMeshComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "MotionControllerComponent.h"
#include "TimerManager.h"


AVB_DynamicActor::AVB_DynamicActor() {
	m_isPickable = true;
	m_isGrab = false;
	PickupMesh->SetSimulatePhysics(false);

}

void AVB_DynamicActor::Pickup_Implementation(USceneComponent * AttachTo)
{
	PickupMesh->SetSimulatePhysics(false);
	if (m_isPickable) {
		UMotionControllerComponent* motionController = Cast<UMotionControllerComponent>(AttachTo);
		if (motionController != nullptr) {
			m_ourMotionController = Cast<ATP_MotionController>(motionController->GetOwner());
			if (m_ourMotionController != nullptr) {
				m_ourMotionController->m_isGrab = true;
				if (m_isDefinedPick) {
					EControllerHand E_hand = m_ourMotionController->Hand;
					FAttachmentTransformRules AttachmentTransformRules(m_attachToSocketRule, m_attachToSocketRule, EAttachmentRule::KeepWorld, false);
					GetRootComponent()->AttachToComponent(motionController->GetChildComponent(0), AttachmentTransformRules, m_attachSocketName);
					if (E_hand == EControllerHand::Left && m_attachToSocketRule == EAttachmentRule::SnapToTarget) {
						//*************Left Hand************//
						UStaticMeshComponent* dynamicActorRootStaticComponent = Cast<UStaticMeshComponent>(GetRootComponent());
						if (dynamicActorRootStaticComponent) {
							dynamicActorRootStaticComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
							USceneComponent* rootComp = GetRootComponent();
							rootComp->SetWorldRotation(FRotator(rootComp->GetComponentRotation().Pitch, rootComp->GetComponentRotation().Yaw, rootComp->GetComponentRotation().Roll + 180.0f));
							dynamicActorRootStaticComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

						}
					}
				}
				else {
					FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::KeepWorld, false);
					GetRootComponent()->AttachToComponent(motionController->GetChildComponent(0), AttachmentTransformRules);
				}
				m_isGrab = true;
			}
		}
		
	}
}

void AVB_DynamicActor::Drop_Implementation()
{
	PickupMesh->SetSimulatePhysics(true);
	FDetachmentTransformRules DetatchmentTransformRules(EDetachmentRule::KeepWorld, false);
	DetachFromActor(DetatchmentTransformRules);
	ResetHandGuestureFunc();
	m_isGrab = false;
	m_ourMotionController->m_isGrab = false;
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

USceneComponent * AVB_DynamicActor::GetComponentByIndex(int compIndex)
{
	if(compIndex == 0)
		return GetRootComponent();
	
	return nullptr;
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

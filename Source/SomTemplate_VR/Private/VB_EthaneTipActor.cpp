// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019

#include "VB_EthaneTipActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"

AVB_EthaneTipActor::AVB_EthaneTipActor() {

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_EthaneTipMesh(TEXT("StaticMesh'/Game/Models/EthaneTip.EthaneTip'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PAR_EthaneParticle(TEXT("ParticleSystem'/Game/Particles/EthaneSplash_P.EthaneSplash_P'"));
	//Set up base mesh
	if (SM_EthaneTipMesh.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_EthaneTipMesh.Object);
	}


}
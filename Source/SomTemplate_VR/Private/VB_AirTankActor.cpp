// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
#include "VB_AirTankActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AVB_AirTankActor::AVB_AirTankActor() {
	ConstructorHelpers::FObjectFinder<UStaticMesh> SM_AirtankMesh(TEXT("StaticMesh'/Game/Models/EthaneTank.EthaneTank'"));
	if (SM_AirtankMesh.Succeeded()) {
		meshComp->SetStaticMesh(SM_AirtankMesh.Object);
	}
	

}
 
// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
#include "VB_FloorActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "VB_DynamicActor.h"

AVB_FloorActor::AVB_FloorActor() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_FloorMesh(TEXT("StaticMesh'/Game/Models/FloorMesh.FloorMesh'"));
	if (SM_FloorMesh.Succeeded()) {
		meshComp->SetStaticMesh(SM_FloorMesh.Object);
	}
	UBoxComponent* floorCollisionBox = Cast<UBoxComponent>(shapeComp);
	if (floorCollisionBox != nullptr) {
		floorCollisionBox->SetBoxExtent(FVector(512.0f, 512.0f, 32.0f));
	}
	
	floorCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AVB_FloorActor::OnComponentBeginOverlap);

}

void AVB_FloorActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr) {
		AVB_DynamicActor* overlappedDynamicActor = Cast<AVB_DynamicActor>(OtherActor);
		if (overlappedDynamicActor != nullptr) {
			overlappedDynamicActor->ResetActorTransformation();
		}
	}
}

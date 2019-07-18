// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PippetHolderActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


AVB_PippetHolderActor::AVB_PippetHolderActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_PippetHolderMesh(TEXT("StaticMesh'/Game/Models/Holder.Holder'"));

	if (SM_PippetHolderMesh.Succeeded()) {
		meshComp->SetStaticMesh(SM_PippetHolderMesh.Object);
	}
	
	shapeComp->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));
	//Cast<UBoxComponent>(shapeComp)->SetBoxExtent(FVector(0.3f, 0.3f, 0.3f));
}

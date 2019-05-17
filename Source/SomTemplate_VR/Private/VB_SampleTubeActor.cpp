// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_SampleTubeActor.h"
#include "Public/Engine.h"

AVB_SampleTubeActor::AVB_SampleTubeActor() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TubeMesh(TEXT("StaticMesh'/Game/Models/SampleHolder.SampleHolder'"));

	if (TubeMesh.Succeeded())
	{
		UStaticMesh* Asset = TubeMesh.Object;
		meshComp->SetStaticMesh(Asset);
		meshComp->SetWorldLocation(FVector(78.75f, -41.11f, 97.36f));
		meshComp->SetWorldScale3D(FVector(0.40625f));
		shapeComp->SetupAttachment(meshComp);
		shapeComp->SetRelativeLocation(FVector(-25.57f, -13.67f, 58.6f));
		shapeComp->SetRelativeScale3D(FVector(0.0625f, 0.0625f, 0.1875f));

	}
}
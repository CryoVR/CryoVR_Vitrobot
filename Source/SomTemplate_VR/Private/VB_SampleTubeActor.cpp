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
	}
}
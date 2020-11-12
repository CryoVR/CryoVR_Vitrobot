// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_CleanTableCompActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"


AVB_CleanTableCompActor::AVB_CleanTableCompActor()
{
	shapeComp->SetRelativeLocationAndRotation(FVector(72.71f, 6.01f, 105.63f), FRotator(0.0f, 0.0f, 0.0f));
	shapeComp->SetRelativeScale3D(FVector(1.2f, 4.0f, 0.5f));
}


// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_LevelScriptActor.h"
#include "VB_VitrobotActor.h"
#include "Components/AudioComponent.h"
#include "VirtualReality/TP_MotionController.h"
#include "VB_TextActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AVB_LevelScriptActor::AVB_LevelScriptActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AVB_LevelScriptActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("==Let's begin=="));

}

void AVB_LevelScriptActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);



}

void AVB_LevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//UE_LOG(LogTemp, Log, TEXT("==%d=="),Status);
	
}

void AVB_LevelScriptActor::SetStatus(int i)
{
	Status = i;
}

int AVB_LevelScriptActor::GetStatus()
{
	return Status;
}
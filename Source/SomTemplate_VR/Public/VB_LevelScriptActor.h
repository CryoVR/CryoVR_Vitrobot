// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "VB_LevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API AVB_LevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

		AVB_LevelScriptActor();
public:
	UFUNCTION()
		void SetStatus(int i);
	UFUNCTION()
		int GetStatus();
	UPROPERTY(EditAnywhere)
		AActor* ACT;


private:
	int Status;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//Tick
	virtual void Tick(float DeltaSeconds) override;
};

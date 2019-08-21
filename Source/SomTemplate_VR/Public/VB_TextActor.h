// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VB_TextActor.generated.h"

class UTextRenderComponent;
class UAudioComponent;

UCLASS()
class SOMTEMPLATE_VR_API AVB_TextActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVB_TextActor();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UTextRenderComponent* TextComp1;

	UPROPERTY(EditAnywhere, Category = "Components")
	UTextRenderComponent* TextComp2;

	UPROPERTY(EditAnywhere, Category = "Components")
	UTextRenderComponent* TextComp3;

	UFUNCTION()
	void SetTextLines(FString string1, FString string2, FString string3);

	UFUNCTION()
	void ClearTextLines();

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* SSound1;

	int delay = 0;

	bool m_HasPlayed = false;
	int CurrentStatus = 0;
};

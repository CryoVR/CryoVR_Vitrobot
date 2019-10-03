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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* TextComp1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* TextComp2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* TextComp3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boolean")
	bool IsShow;

	UFUNCTION()
	void SetTextLines(FString string1, FString string2, FString string3);

	UFUNCTION()
	void ClearTextLines();

	class ALevelScriptActor* GetLevelScriptActor(class ULevel* OwnerLevel = NULL) const;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSoundSuccess;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* SSound1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound4;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound5;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound6;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound7;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound8;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound9;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound10;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound11;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound12;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound13;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound14;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound15;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound16;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound17;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound18;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound19;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound20;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound21;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound22;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound23;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound24;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound25;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound26;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound27;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound28;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound29;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound30;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound31;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound32;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound33;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound34;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound35;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UAudioComponent* SSound36;


	int delay = 0;

	bool m_HasPlayed = false;
	int CurrentStatus = 0;
};

// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_TextActor.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Components/AudioComponent.h"
#include "VB_LevelScriptActor.h"
#include "Kismet/GameplayStatics.h"

AVB_TextActor::AVB_TextActor()
{	
	static ConstructorHelpers::FObjectFinder<USoundWave> S_1(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step02.Step02"));

	PrimaryActorTick.bCanEverTick = true;

	TextComp1 = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextLine1"));
	TextComp1->SetupAttachment(RootComponent);
	TextComp1->SetRelativeLocation(FVector(0.0f, 0.0f, 1.0f));
	TextComp1->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TextComp1->SetText(FText::FromString(TEXT("Testline1")));
	TextComp1->SetRelativeScale3D(FVector(0.8f));
	TextComp1->SetWorldSize(5);
	TextComp1->SetTextRenderColor(FColor::Black);

	TextComp2 = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextLine2"));
	TextComp2->SetupAttachment(RootComponent);
	TextComp2->SetRelativeLocation(FVector(0.0f, 0.0f, 2.0f));
	TextComp2->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TextComp2->SetText(FText::FromString(TEXT("Textline2")));
	TextComp2->SetRelativeScale3D(FVector(0.8f));
	TextComp2->SetWorldSize(5);
	TextComp2->SetTextRenderColor(FColor::Black);

	TextComp3 = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextLine3"));
	TextComp3->SetupAttachment(RootComponent);
	TextComp3->SetRelativeLocation(FVector(0.0f, 0.0f, 3.0f));
	TextComp3->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TextComp3->SetText(FText::FromString(TEXT("Textline3")));
	TextComp3->SetRelativeScale3D(FVector(0.8f));
	TextComp3->SetWorldSize(5);
	TextComp3->SetTextRenderColor(FColor::Black);

	USoundWave* SoundWave = S_1.Object;
	SSound1 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest"));
	SSound1->SetupAttachment(TextComp1);
	SSound1->SetAutoActivate(false);
	SSound1->SetSound(SoundWave);
}


void AVB_TextActor::SetTextLines(FString string1, FString string2, FString string3)
{
	TextComp1->SetText(string1);
	TextComp2->SetText(string2);
	TextComp3->SetText(string3);
}

void AVB_TextActor::ClearTextLines()
{
	TextComp1->SetText("");
	TextComp2->SetText("");
	TextComp3->SetText("");
}

void AVB_TextActor::Tick(float DeltaTime)
{	
	
	AVB_LevelScriptActor *LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	if (CurrentStatus != LSA->GetStatus())
	{
		m_HasPlayed = false;
		CurrentStatus = LSA->GetStatus();
	}
	if (LSA->GetStatus() == 2)
	{
		if (!m_HasPlayed)
		{
			SSound1->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("1", "2", "3");
	}
}
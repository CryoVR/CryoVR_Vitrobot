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
	static ConstructorHelpers::FObjectFinder<USoundWave> S_Success(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/FinishTask.FinishTask"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_1(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step01.Step01"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_2(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step02.Step02"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_3(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step03.Step03"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_4(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step04.Step04"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_5(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step05.Step05"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_6(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step06.Step06"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_7(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/Step07.Step07"));

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

	USoundWave* SoundWaveSuccess = S_Success.Object;
	SSoundSuccess = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTestSuccess"));
	SSoundSuccess->SetupAttachment(TextComp1);
	SSoundSuccess->SetAutoActivate(false);
	SSoundSuccess->SetSound(SoundWaveSuccess);

	USoundWave* SoundWave1 = S_1.Object;
	SSound1 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest1"));
	SSound1->SetupAttachment(TextComp1);
	SSound1->SetAutoActivate(false);
	SSound1->SetSound(SoundWave1);

	USoundWave* SoundWave2 = S_2.Object;
	SSound2 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest2"));
	SSound2->SetupAttachment(TextComp1);
	SSound2->SetAutoActivate(false);
	SSound2->SetSound(SoundWave2);

	USoundWave* SoundWave3 = S_3.Object;
	SSound3 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest3"));
	SSound3->SetupAttachment(TextComp1);
	SSound3->SetAutoActivate(false);
	SSound3->SetSound(SoundWave3);

	USoundWave* SoundWave4 = S_4.Object;
	SSound4 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest4"));
	SSound4->SetupAttachment(TextComp1);
	SSound4->SetAutoActivate(false);
	SSound4->SetSound(SoundWave4);

	USoundWave* SoundWave5 = S_5.Object;
	SSound5 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest5"));
	SSound5->SetupAttachment(TextComp1);
	SSound5->SetAutoActivate(false);
	SSound5->SetSound(SoundWave5);

	USoundWave* SoundWave6 = S_6.Object;
	SSound6 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest6"));
	SSound6->SetupAttachment(TextComp1);
	SSound6->SetAutoActivate(false);
	SSound6->SetSound(SoundWave6);

	USoundWave* SoundWave7 = S_7.Object;
	SSound7 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest7"));
	SSound7->SetupAttachment(TextComp1);
	SSound7->SetAutoActivate(false);
	SSound7->SetSound(SoundWave7);
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
	//UE_LOG(LogTemp, Log, TEXT("==%d=="), delay);
	AVB_LevelScriptActor *LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	if (CurrentStatus != LSA->GetStatus())
	{
		SSoundSuccess->Play();
		m_HasPlayed = false;
		CurrentStatus = LSA->GetStatus();
	}
	if (LSA->GetStatus() == 0)
	{
		if (delay < 1000)
		{
			ClearTextLines();
			SetTextLines("Welcome to our CryoVR Training Module!", "In this section you will learn about the operation of the vitrobot.", "Let's begin!");
			delay++;
			if (!m_HasPlayed)
			{
				SSound1->Play();
				m_HasPlayed = true;
			}
		}
		else if (delay == 1000)
		{
			m_HasPlayed = false;
			delay++;
		}
		else if(delay > 1000)
		{
			ClearTextLines();
			SetTextLines("At the beginning,", "you need to put on the gloves.", "Safety first!");
			if (!m_HasPlayed)
			{
				SSound2->Play();
				m_HasPlayed = true;
			}
		}
	}
	if (LSA->GetStatus() == 1)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound3->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now you need to pick up the dewar.", "It is located on your right hand side.", "");
	}
	if (LSA->GetStatus() == 2)
	{
		if (!m_HasPlayed)
		{
			 
			SSound4->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Before pouring liquid nitrogen,", "you need to remove the cap.", "");
	}
	if (LSA->GetStatus() == 3)
	{
		if (!m_HasPlayed)
		{
			delay = 1001;
			SSound5->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Pour liquid nitrogen into workstation.", "After adding nitrogen, lid the cap of dewar.", "");
	}

	if (LSA->GetStatus() == 4)
	{
			 
		if (delay < 2000)
		{
			ClearTextLines();
			SetTextLines("Now the workstation is cold enough.", "And then add the ethane to the workstation.", "You will see the green ethane tank on the left.");
			delay++;
			if (!m_HasPlayed)
			{
				SSound6->Play();
				m_HasPlayed = true;
			}
		}
		else if (delay == 2000) 
		{
			m_HasPlayed = false;
			delay++;
		}
		else
		{
			ClearTextLines();
			SetTextLines("There are two knobs used to dispense the ethane.", "First, rotate the knob counter-clockwise on the right.", "");
			if (!m_HasPlayed)
			{
				//SSound7->Play();  Logic error here, update it later
				m_HasPlayed = false;
			}
		}
	}
	if (LSA->GetStatus() == 5)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now pick up the ethane dispensing tip", "on the left side of the tank.", "");
	}
	if (LSA->GetStatus() == 6)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Then insert ethane tip into the workstaion.", "", "");
	}
	if (LSA->GetStatus() == 7)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Loacte the mini knob on the back", "of the tank.", "Touch the mini knob to turn on.");
	}
	if (LSA->GetStatus() == 8)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Keep filling until the ehane cup is", "100% full!", "Then reset tip to the ethane tank.");
	}
	if (LSA->GetStatus() == 9)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Touch the mini knob to turn off", "", "");
	}
	if (LSA->GetStatus() == 10)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Rotate the big knob clockwisely", "", "");
	}
	if (LSA->GetStatus() == 11)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now locate the petridish", "Remove the cover of petridish.", "");
	}
	if (LSA->GetStatus() == 12)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("You can see the grid", "Locate the tweezer,", "and grab it");
	}
	if (LSA->GetStatus() == 13)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now use the tweezer to pick the grid up", "After you get the grid.", "Don't forget to lid the petridish!");
	}
	if (LSA->GetStatus() == 14)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now attach the tweezer to the plunger", "", "");
	}
	if (LSA->GetStatus() == 15)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Touch the point on the screen", "to rise the plunger.", "");
	}
	if (LSA->GetStatus() == 16)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Right now locate the pipette", "and pick it up", "");
	}
	if (LSA->GetStatus() == 17)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Insert pipette into the sampletube", "Then you can see the tip attached", "");
	}
	if (LSA->GetStatus() == 19)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Use the pipette to touch the grid", "at the bottom of tweezer", "through the side hole of virtrobot.");
	}
	if (LSA->GetStatus() == 20)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now grab the workstation", "", "");
	}
	if (LSA->GetStatus() == 21)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("And put it on the holder of vitrobot", "", "");
	}
	if (LSA->GetStatus() == 22)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Press the button to rise the workstation.", "", "");
	}
	if (LSA->GetStatus() == 23)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Press the button for the operation", "", "");
	}
	if (LSA->GetStatus() == 24)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("OK, now we are going to transfer your grid to a grid box for storage.", "Grab the tweezers and slowly detach it from the plunger.", "Make sure the grid is always submerged or close to the liquid nitrogen.");
	}
	if (LSA->GetStatus() == 25)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now insert the grid into the grid box.", "", "");
	}
	if (LSA->GetStatus() == 26)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Okay", "Now look at the silver-colored freeze dewar on your right-hand side,", "Pull liquid nitrogen into that to freeze it");
	}
	if (LSA->GetStatus() == 27)
	{
		if (!m_HasPlayed)
		{
			 
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now pick up the gird box tweezer.", "Put it in the freeze dewar and wait for 5 seconds.", "Note that in the real world it may take about 30 seconds");
	}
	if (LSA->GetStatus() == 28)
	{
		if (!m_HasPlayed)
		{

			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Great!", "Now we can pick up the plastic tube in the storage dewar", "The storage dewar is located on the ground.");
	}
	if (LSA->GetStatus() == 29)
	{
		if (!m_HasPlayed)
		{

			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Then put the plastic tube into the freeze dewar", "to keep it's tempreture", "");
	}
	if (LSA->GetStatus() == 30)
	{
		if (!m_HasPlayed)
		{

			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Let's pick up the grid box by using the grid box tweezer", "The grid box is located in the workstation.", "");
	}
	if (LSA->GetStatus() == 31)
	{
		if (!m_HasPlayed)
		{

			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now we can put the grid box into the plastic tube", "", "");
	}
	if (LSA->GetStatus() == 32)
	{
		if (!m_HasPlayed)
		{

			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("We have reached the last step", "Let's put the plastic tube back to storage dewar.", "The cap the dewar with its cover");
	}
	if (LSA->GetStatus() == 33)
	{
		if (!m_HasPlayed)
		{

			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now you have completed all the critical steps in Vitrobot training", "Thanks for experiencing our Vitrobot training module,", "Hope to see you next time!");
	}
}
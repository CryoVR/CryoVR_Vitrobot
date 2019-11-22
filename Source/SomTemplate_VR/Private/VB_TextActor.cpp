// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_TextActor.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "VirtualReality/TP_VirtualRealityPawn_Motion.h"
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
	static ConstructorHelpers::FObjectFinder<USoundWave> S_8(TEXT("/Game/Sounds/6__pick_up_ethane_tip.6__pick_up_ethane_tip"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_9(TEXT("/Game/Sounds/7__insert_in_workstation.7__insert_in_workstation"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_10(TEXT("/Game/Sounds/8_touch_small_knob.8_touch_small_knob"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_11(TEXT("/Game/Sounds/9_reset_tip.9_reset_tip"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_12(TEXT("/Game/Sounds/10__touch_miniknob_turn_off.10__touch_miniknob_turn_off"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_13(TEXT("/Game/Sounds/11__large_knob__turn_off.11__large_knob__turn_off"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_14(TEXT("/Game/Sounds/12_petri_dsih_open.12_petri_dsih_open"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_15(TEXT("/Game/Sounds/13_use_tweezer_pick_gird_up.13_use_tweezer_pick_gird_up"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_16(TEXT("/Game/Sounds/14__lid_petridish_cover.14__lid_petridish_cover"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_17(TEXT("/Game/Sounds/15__attach_tweezer_to_plunger.15__attach_tweezer_to_plunger"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_18(TEXT("/Game/Sounds/16__raise_plunger_by_screen.16__raise_plunger_by_screen"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_19(TEXT("/Game/Sounds/17_pick_up_pippete.17_pick_up_pippete"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_20(TEXT("/Game/Sounds/18_insert_in_sample_tube.18_insert_in_sample_tube"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_21(TEXT("/Game/Sounds/19__open_side_sample_port.19__open_side_sample_port"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_22(TEXT("/Game/Sounds/20_add_sample.20_add_sample"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_23(TEXT("/Game/Sounds/21_workstation_into_vitrobot.21_workstation_into_vitrobot"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_24(TEXT("/Game/Sounds/22_touch_button_rise_workstation.22_touch_button_rise_workstation"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_25(TEXT("/Game/Sounds/23_start_freezing_process.23_start_freezing_process"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_26(TEXT("/Game/Sounds/N_24.N_24"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_27(TEXT("/Game/Sounds/N_25.N_25"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_28(TEXT("/Game/Sounds/N_26.N_26"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_29(TEXT("/Game/Sounds/N_27.N_27"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_30(TEXT("/Game/Sounds/N_28.N_28"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_31(TEXT("/Game/Sounds/N_29.N_29"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_32(TEXT("/Game/Sounds/N_30.N_30"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_33(TEXT("/Game/Sounds/N_31.N_31"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_34(TEXT("/Game/Sounds/N_32.N_32"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_35(TEXT("/Game/Sounds/N_32.N_32"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_36(TEXT("/Game/Sounds/34_say_goodbye_.34_say_goodbye_"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_37(TEXT("/Game/Sounds/Goggles.Goggles"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_38(TEXT("/Game/Sounds/Coat.Coat"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_39(TEXT("/Game/Sounds/N_39.N_39"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_40(TEXT("/Game/Sounds/N_40.N_40"));




	PrimaryActorTick.bCanEverTick = true;

	TextComp1 = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextLine1"));
	//TextComp1->SetupAttachment(RootComponent);
	//TextComp1->SetRelativeLocation(FVector(0.0f, 0.0f, 1.0f));
	//TextComp1->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TextComp1->SetText(FText::FromString(TEXT("Testline1")));
	TextComp1->SetRelativeScale3D(FVector(0.8f));
	TextComp1->SetWorldSize(5);
	TextComp1->SetTextRenderColor(FColor::Black);

	TextComp2 = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextLine2"));
	TextComp2->SetupAttachment(TextComp1);
	TextComp2->SetRelativeLocation(FVector(0.0f, 0.0f, 2.0f));
	TextComp2->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TextComp2->SetText(FText::FromString(TEXT("Textline2")));
	TextComp2->SetRelativeScale3D(FVector(0.8f));
	TextComp2->SetWorldSize(5);
	TextComp2->SetTextRenderColor(FColor::Black);

	TextComp3 = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextLine3"));
	TextComp3->SetupAttachment(TextComp1);
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

	USoundWave* SoundWave8 = S_8.Object;
	SSound8 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest8"));
	SSound8->SetupAttachment(TextComp1);
	SSound8->SetAutoActivate(false);
	SSound8->SetSound(SoundWave8);

	USoundWave* SoundWave9 = S_9.Object;
	SSound9 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest9"));
	SSound9->SetupAttachment(TextComp1);
	SSound9->SetAutoActivate(false);
	SSound9->SetSound(SoundWave9);

	USoundWave* SoundWave10 = S_10.Object;
	SSound10 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest10"));
	SSound10->SetupAttachment(TextComp1);
	SSound10->SetAutoActivate(false);
	SSound10->SetSound(SoundWave10);

	USoundWave* SoundWave11 = S_11.Object;
	SSound11 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest11"));
	SSound11->SetupAttachment(TextComp1);
	SSound11->SetAutoActivate(false);
	SSound11->SetSound(SoundWave11);

	USoundWave* SoundWave12 = S_12.Object;
	SSound12 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest12"));
	SSound12->SetupAttachment(TextComp1);
	SSound12->SetAutoActivate(false);
	SSound12->SetSound(SoundWave12);

	USoundWave* SoundWave13 = S_13.Object;
	SSound13 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest13"));
	SSound13->SetupAttachment(TextComp1);
	SSound13->SetAutoActivate(false);
	SSound13->SetSound(SoundWave13);

	USoundWave* SoundWave14 = S_14.Object;
	SSound14 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest14"));
	SSound14->SetupAttachment(TextComp1);
	SSound14->SetAutoActivate(false);
	SSound14->SetSound(SoundWave14);

	USoundWave* SoundWave15 = S_15.Object;
	SSound15 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest15"));
	SSound15->SetupAttachment(TextComp1);
	SSound15->SetAutoActivate(false);
	SSound15->SetSound(SoundWave15);

	USoundWave* SoundWave16 = S_16.Object;
	SSound16 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest16"));
	SSound16->SetupAttachment(TextComp1);
	SSound16->SetAutoActivate(false);
	SSound16->SetSound(SoundWave16);

	USoundWave* SoundWave17 = S_17.Object;
	SSound17 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest17"));
	SSound17->SetupAttachment(TextComp1);
	SSound17->SetAutoActivate(false);
	SSound17->SetSound(SoundWave17);

	USoundWave* SoundWave18 = S_18.Object;
	SSound18 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest18"));
	SSound18->SetupAttachment(TextComp1);
	SSound18->SetAutoActivate(false);
	SSound18->SetSound(SoundWave18);

	USoundWave* SoundWave19 = S_19.Object;
	SSound19 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest19"));
	SSound19->SetupAttachment(TextComp1);
	SSound19->SetAutoActivate(false);
	SSound19->SetSound(SoundWave19);

	USoundWave* SoundWave20 = S_20.Object;
	SSound20 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest20"));
	SSound20->SetupAttachment(TextComp1);
	SSound20->SetAutoActivate(false);
	SSound20->SetSound(SoundWave20);

	USoundWave* SoundWave21 = S_21.Object;
	SSound21 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest21"));
	SSound21->SetupAttachment(TextComp1);
	SSound21->SetAutoActivate(false);
	SSound21->SetSound(SoundWave21);

	USoundWave* SoundWave22 = S_22.Object;
	SSound22 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest22"));
	SSound22->SetupAttachment(TextComp1);
	SSound22->SetAutoActivate(false);
	SSound22->SetSound(SoundWave22);

	USoundWave* SoundWave23 = S_23.Object;
	SSound23 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest23"));
	SSound23->SetupAttachment(TextComp1);
	SSound23->SetAutoActivate(false);
	SSound23->SetSound(SoundWave23);

	USoundWave* SoundWave24 = S_24.Object;
	SSound24 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest24"));
	SSound24->SetupAttachment(TextComp1);
	SSound24->SetAutoActivate(false);
	SSound24->SetSound(SoundWave24);

	USoundWave* SoundWave25 = S_25.Object;
	SSound25 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest25"));
	SSound25->SetupAttachment(TextComp1);
	SSound25->SetAutoActivate(false);
	SSound25->SetSound(SoundWave25);

	USoundWave* SoundWave26 = S_26.Object;
	SSound26 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest26"));
	SSound26->SetupAttachment(TextComp1);
	SSound26->SetAutoActivate(false);
	SSound26->SetSound(SoundWave26);

	USoundWave* SoundWave27 = S_27.Object;
	SSound27 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest27"));
	SSound27->SetupAttachment(TextComp1);
	SSound27->SetAutoActivate(false);
	SSound27->SetSound(SoundWave27);

	USoundWave* SoundWave28 = S_28.Object;
	SSound28 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest28"));
	SSound28->SetupAttachment(TextComp1);
	SSound28->SetAutoActivate(false);
	SSound28->SetSound(SoundWave28);

	USoundWave* SoundWave29 = S_29.Object;
	SSound29 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest29"));
	SSound29->SetupAttachment(TextComp1);
	SSound29->SetAutoActivate(false);
	SSound29->SetSound(SoundWave29);

	USoundWave* SoundWave30 = S_30.Object;
	SSound30 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest30"));
	SSound30->SetupAttachment(TextComp1);
	SSound30->SetAutoActivate(false);
	SSound30->SetSound(SoundWave30);

	USoundWave* SoundWave31 = S_31.Object;
	SSound31 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest31"));
	SSound31->SetupAttachment(TextComp1);
	SSound31->SetAutoActivate(false);
	SSound31->SetSound(SoundWave31);

	USoundWave* SoundWave32 = S_32.Object;
	SSound32 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest32"));
	SSound32->SetupAttachment(TextComp1);
	SSound32->SetAutoActivate(false);
	SSound32->SetSound(SoundWave32);

	USoundWave* SoundWave33 = S_33.Object;
	SSound33 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest33"));
	SSound33->SetupAttachment(TextComp1);
	SSound33->SetAutoActivate(false);
	SSound33->SetSound(SoundWave33);

	USoundWave* SoundWave34 = S_34.Object;
	SSound34 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest34"));
	SSound34->SetupAttachment(TextComp1);
	SSound34->SetAutoActivate(false);
	SSound34->SetSound(SoundWave34);

	USoundWave* SoundWave35 = S_35.Object;
	SSound35 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest35"));
	SSound35->SetupAttachment(TextComp1);
	SSound35->SetAutoActivate(false);
	SSound35->SetSound(SoundWave35);

	USoundWave* SoundWave36 = S_36.Object;
	SSound36 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest36"));
	SSound36->SetupAttachment(TextComp1);
	SSound36->SetAutoActivate(false);
	SSound36->SetSound(SoundWave36);

	USoundWave* SoundWave37 = S_37.Object;
	SSound37 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest37"));
	SSound37->SetupAttachment(TextComp1);
	SSound37->SetAutoActivate(false);
	SSound37->SetSound(SoundWave37);

	USoundWave* SoundWave38 = S_38.Object;
	SSound38 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest38"));
	SSound38->SetupAttachment(TextComp1);
	SSound38->SetAutoActivate(false);
	SSound38->SetSound(SoundWave38);

	USoundWave* SoundWave39 = S_39.Object;
	SSound39 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest39"));
	SSound39->SetupAttachment(TextComp1);
	SSound39->SetAutoActivate(false);
	SSound39->SetSound(SoundWave39);

	USoundWave* SoundWave40 = S_40.Object;
	SSound40 = CreateAbstractDefaultSubobject<UAudioComponent>(TEXT("AudioTest40"));
	SSound40->SetupAttachment(TextComp1);
	SSound40->SetAutoActivate(false);
	SSound40->SetSound(SoundWave40);
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
	ATP_VirtualRealityPawn_Motion *VRP = Cast<ATP_VirtualRealityPawn_Motion>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (CurrentStatus != LSA->GetStatus())
	{
		SSoundSuccess->Play();
		m_HasPlayed = false;
		float currentscore = VRP->GetScore()+3.0f;
		VRP->SetScore(currentscore);
		int currenterror = VRP->GetErrors() - 1;
		VRP->SetErrors(currenterror);
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
			SSoundSuccess->Play();
			SSound8->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now pick up the ethane dispensing tip", "on the left side of the tank.", "");
	}
	if (LSA->GetStatus() == 6)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound9->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Then insert ethane tip into the workstation.", "", "");
	}
	if (LSA->GetStatus() == 7)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound10->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Locate the mini knob on the back", "of the tank.", "Touch the mini knob to turn on.");
	}
	if (LSA->GetStatus() == 8)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound11->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Keep filling until the ethane cup is", "100% full!", "Then reset tip to the ethane tank.");
	}
	if (LSA->GetStatus() == 9)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound12->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Touch the mini knob to turn off.", "", "");
	}
	if (LSA->GetStatus() == 10)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound13->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Rotate the big knob clock-wisely.", "", "");
	}
	if (LSA->GetStatus() == 11)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound14->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now locate the petridish", "Remove the cover of petridish.", "");
	}
	if (LSA->GetStatus() == 12)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound15->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("You can see the grid", "Locate the tweezer,", "and grab it");
	}
	if (LSA->GetStatus() == 13)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound16->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now use the tweezer to pick the grid up", "After you get the grid.", "Don't forget to lid the petridish!");
	}
	if (LSA->GetStatus() == 14)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound17->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now attach the tweezer to the plunger", "", "");
	}
	if (LSA->GetStatus() == 15)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound18->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Touch the point on the screen", "to rise the plunger.", "");
	}
	if (LSA->GetStatus() == 16)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound19->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Right now locate the pipette", "and pick it up", "");
	}
	if (LSA->GetStatus() == 17)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound20->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Insert pipette into the sample tube", "Then you can see the tip attached", "");
	}
	if (LSA->GetStatus() == 19)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound22->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Use the pipette to touch the grid", "at the bottom of tweezer", "through the side hole of virtrobot.");
	}
	if (LSA->GetStatus() == 20)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound23->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now grab the workstation", "", "");
	}
	if (LSA->GetStatus() == 21)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			//SSound24->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("And put it on the holder of vitrobot", "", "");
	}
	if (LSA->GetStatus() == 22)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound24->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Press the button to rise the workstation.", "", "");
	}
	if (LSA->GetStatus() == 23)
	{
		if (!m_HasPlayed)
		{
			 
			SSoundSuccess->Play();
			SSound25->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Press the button for the operation", "", "");
	}
	if (LSA->GetStatus() == 24)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound26->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("OK, now we are going to transfer your grid to a grid box for storage.", "Grab the tweezers and slowly detach it from the plunger.", "Make sure the grid is always submerged or close to the liquid nitrogen.");
	}
	if (LSA->GetStatus() == 25)
	{
		if (!m_HasPlayed)
		{
			 
			SSoundSuccess->Play();
			SSound27->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now insert the grid into the grid box.", "", "");
	}
	if (LSA->GetStatus() == 26)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound28->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Okay", "Now look at the silver-colored freeze dewar on your right-hand side,", "pour liquid nitrogen into that to freeze it");
	}
	if (LSA->GetStatus() == 27)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound29->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now pick up the grid box tweezer.", "Put it in the freeze dewar and wait for 5 seconds.", "Note that in the real world it may take about 30 seconds");
	}
	if (LSA->GetStatus() == 28)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound30->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Great!", "Now we can pick up the plastic tube in the storage dewar", "The storage dewar is located on the ground.");
	}
	if (LSA->GetStatus() == 29)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound31->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Then put the plastic tube into the freeze dewar", "to keep it's temprature", "");
	}
	if (LSA->GetStatus() == 30)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound32->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Let's pick up the grid box by using the grid box tweezer", "The grid box is located in the workstation.", "");
	}
	if (LSA->GetStatus() == 31)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound33->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now we can put the grid box into the plastic tube", "", "");
	}
	if (LSA->GetStatus() == 32)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound35->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("We have reached the last step", "Let's put the plastic tube back to storage dewar.", "Then cap the dewar with its cover");
	}
	if (LSA->GetStatus() == 33)
	{	
		VRP->SetisFinished(true);
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound36->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now you have completed all the critical steps in Vitrobot training", "Thanks for experiencing our Vitrobot training module,", "Hope to see you next time!");
	}
	if (LSA->GetStatus() == 34)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound38->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Then we need to wear the safty coat.", "It's located on your back side", "Touch the coat to equip it.");
	}
	if (LSA->GetStatus() == 35)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound37->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now put on the goggles.", "They will also prevent you from some dangerous conditions", "Again, safety first!");
	}
	if (LSA->GetStatus() == 36)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound39->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now we need to pickup the workstation", "It is in the hood", "move it to the table for future operation");
	}
	if (LSA->GetStatus() == 37)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound40->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Ok.", "Let's put the workstation back to the hood", "");
	}
	if (LSA->GetStatus() == 38)
	{
		if (!m_HasPlayed)
		{
			SSoundSuccess->Play();
			SSound40->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now we need to put all the devices back to the cart.", "Keep the lab environment clean!", "");
	}
}
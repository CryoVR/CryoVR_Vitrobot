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
	static ConstructorHelpers::FObjectFinder<USoundWave> S_1(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v0.v0"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_2(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v1.v1"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_3(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v2.v2"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_4(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v3.v3"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_5(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v4.v4"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_6(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v5.v5"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_7(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v6.v6"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_8(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v7.v7"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_9(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v8.v8"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_10(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v9.v9"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_11(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v10.v10"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_12(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v11.v11"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_13(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v12.v12"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_14(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v13.v13"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_15(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v14.v14"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_16(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v15.v15"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_17(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v16.v16"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_18(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/new_v17.new_v17"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_19(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v18.v18"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_20(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v19.v19"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_21(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v20.v20"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_22(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v21.v21"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_23(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/vFix22.vFix22"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_24(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/new_v24.new_v24"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_25(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v25.v25"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_26(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v26.v26"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_27(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v27.v27"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_28(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v27_5.v27_5"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_29(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v28.v28"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_30(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v29.v29"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_31(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v30.v30"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_32(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v31.v31"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_33(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v32.v32"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_34(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v33.v33"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_35(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v33.v33"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_36(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v34.v34"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_37(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v36.v36"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_38(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v35.v35"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_39(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v37.v37"));
	static ConstructorHelpers::FObjectFinder<USoundWave> S_40(TEXT("/Game/Test_Geometry/Test_Textures/Sounds/v38.v38"));
	



	PrimaryActorTick.bCanEverTick = true;

	TextComp1 = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextLine1"));
	//TextComp1->SetupAttachment(RootComponent);
	//TextComp1->SetRelativeLocation(FVector(0.0f, 0.0f, 1.0f));
	//TextComp1->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TextComp1->SetText(FText::FromString(TEXT("Testline1")));
	TextComp1->SetRelativeScale3D(FVector(0.8f));
	TextComp1->SetWorldSize(5);
	TextComp1->SetTextRenderColor(FColor::Black);

	WhiteBoard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Whiteboard"));
	WhiteBoard->SetupAttachment(TextComp1);

	BlackBoard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Blackboard"));
	BlackBoard->SetupAttachment(TextComp1);


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
	AVB_LevelScriptActor* LSA = Cast<AVB_LevelScriptActor>(GetWorld()->GetLevelScriptActor());
	ATP_VirtualRealityPawn_Motion* VRP = Cast<ATP_VirtualRealityPawn_Motion>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (CurrentStatus != LSA->GetStatus() && LSA != nullptr)
	{
		SSoundSuccess->Play();
		m_HasPlayed = false;
		float currentscore = VRP->GetScore() + 3.0f;
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
		else if (delay > 1000)
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
			SSound39->Stop();
			SSoundSuccess->Play();
			SSound3->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now pick up the dewar.", "", "");
	}
	if (LSA->GetStatus() == 2)
	{
		if (!m_HasPlayed)
		{
			SSound3->Stop();
			SSound4->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Uncap the liquid nitrogen dewar", "", "");
	}
	if (LSA->GetStatus() == 3)
	{
		if (!m_HasPlayed)
		{
			SSound4->Stop();
			delay = 1001;
			SSound5->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Then, pour liquid nitrogen into workstation.", "After adding nitrogen, recap the dewar.", "");
	}

	if (LSA->GetStatus() == 4)
	{

		if (delay < 2000)
		{
			ClearTextLines();
			SetTextLines("Now the workstation is cooled down.", "It's time to add ethane to the workstation.", "The green ethane tank is on the left.");
			delay++;
			if (!m_HasPlayed)
			{
				SSound5->Stop();
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
			SetTextLines("There are two knobs used to dispense the ethane.", "First, rotate the large knob counter-clockwise.", "");
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
			SSound6->Stop();
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
			SSound8->Stop();
			SSoundSuccess->Play();
			SSound9->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Place the ethane dispensing tip into the center cup of workstation.", "", "");
	}
	if (LSA->GetStatus() == 7)
	{
		if (!m_HasPlayed)
		{
			SSound9->Stop();
			SSoundSuccess->Play();
			SSound10->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now, turn the small knob located on", "the backside of the tank to start dispensing.", "Ethane is flammable - be careful!");
	}
	if (LSA->GetStatus() == 8)
	{
		if (!m_HasPlayed)
		{
			SSound10->Stop();
			SSoundSuccess->Play();
			SSound11->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Keep filling until the ethane cup is", "100% full!", "Then, put the ethane dispensing tip back.");
	}
	if (LSA->GetStatus() == 9)
	{
		if (!m_HasPlayed)
		{
			SSound11->Stop();
			SSoundSuccess->Play();
			SSound12->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Turn the small knob on the", "ethane tank to stop dispensing.", "");
	}
	if (LSA->GetStatus() == 10)
	{
		if (!m_HasPlayed)
		{
			SSound12->Stop();
			SSoundSuccess->Play();
			SSound13->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now turn off the ethan tank completely ", "by turning the big knob clockwise.", "");
	}
	if (LSA->GetStatus() == 11)
	{
		if (!m_HasPlayed)
		{
			SSound13->Stop();
			SSoundSuccess->Play();
			SSound14->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now, locate the petridish on the desk", " and remove the cover.", "");
	}
	if (LSA->GetStatus() == 12)
	{
		if (!m_HasPlayed)
		{
			SSound14->Stop();
			SSoundSuccess->Play();
			SSound15->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("You can see the grid in the petri dish!", "Grab the tweezers", "on the desk.");
	}
	if (LSA->GetStatus() == 13)
	{
		if (!m_HasPlayed)
		{
			SSound15->Stop();
			SSoundSuccess->Play();
			SSound16->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Pick up the grid with the", "tweezers, and", "don't forget to cover the petri dish!");
	}
	if (LSA->GetStatus() == 14)
	{
		if (!m_HasPlayed)
		{
			SSound16->Stop();
			SSoundSuccess->Play();
			SSound17->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Attach the tweezers to the plunger", "", "");
	}
	if (LSA->GetStatus() == 15)
	{
		if (!m_HasPlayed)
		{
			SSound17->Stop();
			SSoundSuccess->Play();
			SSound18->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Use the stylus to press the button that says ", " 'START PROCEDURE' on the Vitrobot screen once", "to raise the plunger.");
	}
	if (LSA->GetStatus() == 16)
	{
		if (!m_HasPlayed)
		{
			SSound18->Stop();
			SSoundSuccess->Play();
			SSound19->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Now, pick up your pipette!", "", "");
	}
	if (LSA->GetStatus() == 17)
	{
		if (!m_HasPlayed)
		{
			SSound19->Stop();
			SSoundSuccess->Play();
			SSound20->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Use the pipette to pick up your", "sample from the ", "yellow tube rack on the left.");
	}

	if (LSA->GetStatus() == 18)
	{
		if (!m_HasPlayed)
		{
			SSound20->Stop();
			SSoundSuccess->Play();
			SSound21->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Open the side port on the", "right side of the Vitrobot", "");
	}

	if (LSA->GetStatus() == 19)
	{
		if (!m_HasPlayed)
		{
			SSound21->Stop();
			SSoundSuccess->Play();
			SSound22->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Use the pipette to touch the grid", "at the bottom of tweezers", "through the side port.");
	}
	if (LSA->GetStatus() == 20)
	{
		if (!m_HasPlayed)
		{
			SSound22->Stop();
			SSoundSuccess->Play();
			SSound23->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Grab the workstation", "", "");
	}
	if (LSA->GetStatus() == 21)
	{
		if (!m_HasPlayed)
		{
			SSound23->Stop();
			SSoundSuccess->Play();
			//SSound24->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("and put it on the workstation platform.", "", "");
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
		SetTextLines("Use the stylus to press 'CONTINUE' once", "on the Vitrobot screen", "to start blotting and plunging!");
	}
	//if (LSA->GetStatus() == 23)
	//{
	//	if (!m_HasPlayed)
	//	{
	//		 
	//		SSoundSuccess->Play();
	//		SSound25->Play();
	//		m_HasPlayed = true;
	//	}
	//	ClearTextLines();
	//	SetTextLines("Press the button for the operation", "", "");
	//}
	if (LSA->GetStatus() == 24)
	{
		if (!m_HasPlayed)
		{
			SSound24->Stop();
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
			SSound26->Stop();
			SSoundSuccess->Play();
			SSound27->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Carefully insert the grid into the blue grid box", "that's already in the workstation.", "");
	}
	if (LSA->GetStatus() == 26)
	{
		if (!m_HasPlayed)
		{
			SSound27->Stop();
			SSoundSuccess->Play();
			SSound28->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Okay,", "fill the temporary storage dewar with", "with liquid nitrogen to cool it down.");
	}
	if (LSA->GetStatus() == 27)
	{
		if (!m_HasPlayed)
		{
			SSound28->Stop();
			SSoundSuccess->Play();
			SSound29->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Pick up the large grid box tweezers", "and put them in the temporary storage dewar for cooldown.", "");
	}
	if (LSA->GetStatus() == 28)
	{
		if (!m_HasPlayed)
		{
			SSound29->Stop();
			SSoundSuccess->Play();
			SSound30->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Great! Now let's use the large liquid nitrogen storage dewar on the floor to your right.", "Uncap it and take out the plastic tube.", "The tube is used for storing grid boxes!");
	}
	if (LSA->GetStatus() == 29)
	{
		if (!m_HasPlayed)
		{
			SSound30->Stop();
			SSoundSuccess->Play();
			SSound31->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Quickly transfer the plastic tube into", "the temporary storage dewar.", "");
	}
	if (LSA->GetStatus() == 30)
	{
		if (!m_HasPlayed)
		{
			SSound31->Stop();
			SSoundSuccess->Play();
			SSound32->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Pick up your grid box from the workstation", "using the large, cooled down tweezers.", "");
	}
	if (LSA->GetStatus() == 31)
	{
		if (!m_HasPlayed)
		{
			SSound32->Stop();
			SSoundSuccess->Play();
			SSound33->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("and quickly put it into the plastic tube ", "that's in the temporary storage dewar", "");
	}
	if (LSA->GetStatus() == 32)
	{
		if (!m_HasPlayed)
		{
			SSound33->Stop();
			SSoundSuccess->Play();
			SSound35->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("We have reached the last step!", "Put the plastic tube back into the large storage dewar", "and recap it!");
	}
	if (LSA->GetStatus() == 33)
	{
		VRP->SetisFinished(true);
		if (!m_HasPlayed)
		{
			SSound35->Stop();
			SSoundSuccess->Play();
			SSound36->Play();
			m_HasPlayed = true;
		}
		ClearTextLines();
		SetTextLines("Thank you for finishing the Vitrobot training!", "", "Keep practicing!");
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
		SetTextLines("Pick up the workstation", "which is in the hood", "and put it on your desk!");
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
		SetTextLines("Ok.", "Put the workstation back into the hood", "");
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
		SetTextLines("Ok.", "Put the workstation back into the hood", "");
	}
}

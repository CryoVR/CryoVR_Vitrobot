// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_TweezerActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "VB_PetridishActor.h"
#include "VB_PetridishCoverActor.h"
#include "VB_StaticActor.h"


// Sets default values
AVB_TweezerActor::AVB_TweezerActor()
{
	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("capsuleComp"));
	capsuleComp->SetGenerateOverlapEvents(true);
	capsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	capsuleComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Cast<UCapsuleComponent>(capsuleComp)->SetCapsuleSize(1.0f, 1.0f);
	capsuleComp->SetRelativeLocation(FVector(0.0f, 0.0f, -7.0f));
	capsuleComp->SetRelativeScale3D(FVector(0.02f, 0.02f, 0.02f));
	capsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_TweezerActor::OnOverlapBegin);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Tweezer(TEXT("StaticMesh'/Game/Models/Tweezer.Tweezer'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Tweezer_Grid(TEXT("StaticMesh'/Game/Models/Tweezer_Grid.Tweezer_Grid'"));

	if (SM_Tweezer.Succeeded()) {
		PickupMesh->SetStaticMesh(SM_Tweezer.Object);
		capsuleComp->SetupAttachment(PickupMesh);
	}

	tweezer_grid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tweezer_grid"));
	tweezer_grid->SetGenerateOverlapEvents(false);
	tweezer_grid->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	tweezer_grid->SetVisibility(false);
	tweezer_grid->SetRelativeLocation(FVector(0.0f, 0.0f, -6.92f));
	tweezer_grid->SetupAttachment(PickupMesh);

	if (SM_Tweezer_Grid.Succeeded()) {
		tweezer_grid->SetStaticMesh(SM_Tweezer_Grid.Object);
	}
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AVB_TweezerActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AVB_PetridishActor* petridishActor = Cast<AVB_PetridishActor>(OtherActor);
	AVB_PetridishCoverActor* petridishCoverActor = Cast<AVB_PetridishCoverActor>(OtherActor);
	//UE_LOG(LogTemp, Log, TEXT("=======================Code Executed01==========================="));
	if (petridishActor != nullptr && petridishActor->getState()) {
		//FString name = OtherComp->GetAttachParent()->GetName();
		//UE_LOG(LogTemp, Log, TEXT("==Index = %s"), *name);
		if (petridishActor->GetGrid() == OtherComp->GetAttachParent()) {
			//UE_LOG(LogTemp, Log, TEXT("=======================Code Executed03==========================="));
			petridishActor->GetGrid()->SetVisibility(false);
			tweezer_grid->SetVisibility(true);
		}
	}
}

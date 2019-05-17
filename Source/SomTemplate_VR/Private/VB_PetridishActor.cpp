// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PetridishActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"

AVB_PetridishActor::AVB_PetridishActor() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_GridHolderDMesh(TEXT("StaticMesh'/Game/Models/GridHolderDMesh.GridHolderDMesh'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Petridish_Grid(TEXT("StaticMesh'/Game/Models/Tweezer_Grid.Tweezer_Grid'"));
	
	if (SM_GridHolderDMesh.Succeeded()) {
		meshComp->SetStaticMesh(SM_GridHolderDMesh.Object);
	}



	petridish_grid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Petridish_grid"));
	petridish_grid->SetGenerateOverlapEvents(true);
	petridish_grid->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	petridish_grid->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	petridish_grid->SetVisibility(true);
	petridish_grid->SetRelativeLocation(FVector(0.0f, 0.0f, 0.3f));
	petridish_grid->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
	petridish_grid->SetupAttachment(meshComp);

	
	if (SM_Petridish_Grid.Succeeded()) {
		petridish_grid->SetStaticMesh(SM_Petridish_Grid.Object);
	}


	shapeComp->DestroyComponent();
	shapeComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Petridish"));
	shapeComp->SetGenerateOverlapEvents(true);
	shapeComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	shapeComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Cast<UCapsuleComponent>(shapeComp)->SetCapsuleSize(1.0f, 1.0f);
	shapeComp->SetupAttachment(petridish_grid);


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

UStaticMeshComponent* AVB_PetridishActor::GetGrid()
{
	return petridish_grid;
}

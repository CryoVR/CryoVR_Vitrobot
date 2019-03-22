// Fill out your copyright notice in the Description page of Project Settings.

#include "Card.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Components/InputComponent.h"


// Sets default values
ACard::ACard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
		ProxSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this,
			TEXT("Proximity Sphere"));
	ProxSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	ProxSphere->SetSphereRadius(32.0f);
	// Code to make ANPC::Prox() run when this proximity sphere 
	// overlaps another actor. 
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ACard::Prox);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int ACard::Prox_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (Cast<ACard>(OtherActor) == nullptr) {
		return -1;
	}
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController)
	{
		static const FString ScrollingMessage(TEXT("Hello World: "));
		const int32 AlwaysAddKey = -1;
		GEngine->AddOnScreenDebugMessage(AlwaysAddKey, 0.5f, FColor::Yellow, ScrollingMessage);
	}
	return 0;
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




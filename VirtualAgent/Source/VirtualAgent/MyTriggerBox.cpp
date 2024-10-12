// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "Components/BoxComponent.h" // For the Trigger Box
#include "Blueprint/UserWidget.h" // For the Widget system
#include "GameFramework/PlayerController.h" // To access the player controller
#include "Kismet/GameplayStatics.h" // For getting the player and other gameplay utilities

// Constructor: Sets up the TriggerBox component and configures it to detect overlap events
AARTextBoxTrigger::AARTextBoxTrigger()
{
    // Create and initialize the TriggerBox component
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox; // Make the trigger box the root component of the actor

    // Configure the TriggerBox collision to only trigger overlap events
    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
    TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

    // Bind the OnComponentBeginOverlap event to the OnOverlapBegin function
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AARTextBoxTrigger::OnOverlapBegin);
}

// Called when the game starts or when the actor is spawned
void AARTextBoxTrigger::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame (can be removed if you're not using it)
void AARTextBoxTrigger::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// This function is called when an actor enters the TriggerBox
void AARTextBoxTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    // Ensure the overlapping actor is valid and is not the trigger itself
    if (OtherActor && OtherActor != this)
    {
        // Get a reference to the player controller
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

        // Check if the overlapping actor is the player (the pawn controlled by the player controller)
        if (PlayerController && OtherActor == PlayerController->GetPawn())
        {
            // Check if the widget class is set in the editor (ensure the ARTextBoxWidgetClass is valid)
            if (ARTextBoxWidgetClass)
            {
                // Create the widget for the player (this is the AR text box widget)
                UUserWidget* ARTextBoxWidget = CreateWidget<UUserWidget>(PlayerController, ARTextBoxWidgetClass);

                // If the widget was successfully created, add it to the viewport
                if (ARTextBoxWidget)
                {
                    ARTextBoxWidget->AddToViewport(); // Display the widget on the screen
                }
            }
        }
    }
}
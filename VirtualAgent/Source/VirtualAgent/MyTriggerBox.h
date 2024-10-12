// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerBox.generated.h"

// Forward declarations to avoid circular dependencies
class UBoxComponent;
class UUserWidget;

UCLASS()
class YOURPROJECTNAME_API AARTextBoxTrigger : public AActor
{
    GENERATED_BODY()

public:
    // Constructor to initialize the actor
    AARTextBoxTrigger();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame (optional, can be removed if not needed)
    virtual void Tick(float DeltaTime) override;

    // The trigger box component that will detect overlaps with the player
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* TriggerBox;

    // The class of the widget that will be displayed when the player enters the trigger box
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> ARTextBoxWidgetClass;

    // Function that handles what happens when an actor overlaps with the trigger box
    UFUNCTION()
    void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};
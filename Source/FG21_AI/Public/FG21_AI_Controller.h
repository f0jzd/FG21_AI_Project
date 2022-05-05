// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "FG21_AI_Controller.generated.h"

UCLASS(Blueprintable)
class FG21_AI_API AFG21_AI_Controller : public AAIController
{

	GENERATED_BODY()
	AFG21_AI_Controller();

	virtual void BeginPlay() override;


	UFUNCTION()
	void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimuli);

private:

	UPROPERTY(EditDefaultsOnly)
	UAIPerceptionComponent* PerceptionComp = nullptr;


	UPROPERTY()
		AActor* PlayerRef = nullptr;


	UPROPERTY()
		UBlackboardComponent* BBComp = nullptr;

public:

	float GetPlayerDistance();

};

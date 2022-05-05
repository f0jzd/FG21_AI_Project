// Fill out your copyright notice in the Description page of Project Settings.


#include "FG21_AI_Controller.h"

#include "FG21_AI_Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "FG21_AI/FG21_AICharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"

AFG21_AI_Controller::AFG21_AI_Controller()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComp"));

	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AFG21_AI_Controller::OnPerceptionUpdated);
	

}

void AFG21_AI_Controller::BeginPlay()
{
	Super::BeginPlay();

	PlayerRef = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);


	BBComp = GetBlackboardComponent();



	BBComp->SetValueAsObject("Player", PlayerRef);


}

void AFG21_AI_Controller::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimuli)
{
	if (AFG21_AICharacter* Char = Cast<AFG21_AICharacter>(Actor))
	{
		if (BBComp == nullptr)
		{
			BBComp = GetBlackboardComponent();
		}

		if (Stimuli.WasSuccessfullySensed())
		{
			
			BBComp->SetValueAsBool("HasLOS", true);
			BBComp->SetValueAsBool("Alert", true);
			BBComp->ClearValue("LastSpottedLocation");
			return;
		}
		//We are removing clear value since we do not want to keep updating the player variable

		BBComp->SetValueAsVector("LastSpottedLocation",Char->GetActorLocation());

		BBComp->SetValueAsBool("HasLOS", false);


	}
	

}

float AFG21_AI_Controller::GetPlayerDistance()
{
	return FVector::Distance(PlayerRef->GetActorLocation(), GetPawn()->GetActorLocation());
}

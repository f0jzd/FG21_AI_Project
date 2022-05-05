// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_CheckDistance.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UBTD_CheckDistance::UBTD_CheckDistance()
{
	A.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTD_CheckDistance, A), AActor::StaticClass());
	B.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTD_CheckDistance, B), AActor::StaticClass());

}

bool UBTD_CheckDistance::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{

	const AActor* ActorA = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(A.SelectedKeyName));
	const AActor* ActorB = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(B.SelectedKeyName));


	if (ActorA != nullptr && ActorB != nullptr)
	{

		float Distance = FVector::Distance(ActorA->GetActorLocation(),ActorB->GetActorLocation());
		return Distance >= MinDistance;
	}

	return Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
}

void UBTD_CheckDistance::OnNodeActivation(FBehaviorTreeSearchData& SearchData)
{


	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, TEXT("Calcuate Distance was actived(?)"));


	Super::OnNodeActivation(SearchData);
}

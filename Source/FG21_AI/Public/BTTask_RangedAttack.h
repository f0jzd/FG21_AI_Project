// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RangedAttack.generated.h"

/**
 * 
 */
UCLASS()
class FG21_AI_API UBTTask_RangedAttack : public UBTTaskNode
{
	GENERATED_BODY()


		UBTTask_RangedAttack();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector PlayerKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimeBetweenShots = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ShotCount = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ShotRange = 5000.f;


protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	float TimeStamp = -1.0f;

	UPROPERTY()
		AActor* PlayerRef = nullptr;

	int32 AccumulatedShots = 0;


	void Fire(AActor* FiringActor);
};

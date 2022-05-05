// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_CheckDistance.generated.h"



UCLASS()
class FG21_AI_API UBTD_CheckDistance : public UBTDecorator
{
	GENERATED_BODY()

	UBTD_CheckDistance();


protected:

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	virtual void OnNodeActivation(FBehaviorTreeSearchData& SearchData) override;

	

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FBlackboardKeySelector A;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector B;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MinDistance = 1000.f;

};

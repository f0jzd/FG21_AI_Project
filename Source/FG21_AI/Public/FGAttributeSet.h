// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FGAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FG21_AI_API UFGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UFGAttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
		FGameplayAttribute Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
		FGameplayAttribute Stamina;



	
};

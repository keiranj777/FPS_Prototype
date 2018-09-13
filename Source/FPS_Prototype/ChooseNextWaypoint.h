// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PROTOTYPE_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    
protected:
    // expose index key - in patrol route
    UPROPERTY(EditAnywhere, Category="Blackboard")
    struct FBlackboardKeySelector IndexKey;
	
	
};

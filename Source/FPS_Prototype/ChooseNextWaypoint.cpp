// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrollingGuard.h" // TODO remove coupling
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // get the patrol points
    auto AIController = OwnerComp.GetAIOwner();
    // get the controlled pawn
    auto ControlledPawn = AIController->GetPawn();
    auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
    auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;
    
    // set next waypoint
    
    // use blackboardcomponent.h methods
    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    // get the value as an int using the key name
    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    
    BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
    //TODO protect against empty patrol routes
    
    auto NextIndex = (Index + 1) % PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
    
    return EBTNodeResult::Succeeded;
}


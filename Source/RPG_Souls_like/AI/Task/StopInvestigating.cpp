// Fill out your copyright notice in the Description page of Project Settings.


#include "StopInvestigating.h"
#include "RPG_Souls_like/AI/AIController/BaseAIController.h"
#include "RPG_Souls_like/AI/BlackBoard/BlackboardKeys.h"
#include "BehaviorTree/BlackboardComponent.h"

UStopInvestigating::UStopInvestigating(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Stop Investigating");
}

EBTNodeResult::Type UStopInvestigating::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//get the AI controller and write false to the blackboard key "IsInvestigating"
	auto const Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());

	if (Controller) {
		Controller->GetBlackboard()->SetValueAsBool(GetSelectedBlackboardKey(), false);

		//finish with success
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BossAttackNotifyState.h"
#include "Components/SkeletalMeshComponent.h"
#include "RPG_Souls_like/BossCharacter.h"

void UBossAttackNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	if (MeshComp && MeshComp->GetOwner()) {
		ABossCharacter* const Boss = Cast<ABossCharacter>(MeshComp->GetOwner());
		if (Boss) {
			Boss->AttackStart();
		}
	}
}
void UBossAttackNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp && MeshComp->GetOwner()){
		ABossCharacter* const Boss = Cast<ABossCharacter>(MeshComp->GetOwner());
		if (Boss) {
			Boss->AttackEnd();
		}
	}
}

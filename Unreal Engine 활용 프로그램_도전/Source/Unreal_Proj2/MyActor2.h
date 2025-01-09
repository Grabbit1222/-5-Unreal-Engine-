// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class UNREAL_PROJ2_API AMyActor2 : public AActor
{
	GENERATED_BODY()
protected:
	// 시작점
	FVector2D Start;
	int32 evCnt;
	float totDist;

	int32 CurrentStep; // 현재 이동 단계
	FVector2D CurrentPosition; // 현재 위치
	FVector2D NewPosition; // 새 위치

public:	
	// Sets default values for this actor's properties
	AMyActor2();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 두 벡터 사이의 거리
	float distance(FVector2D first, FVector2D second);

	// 10회 이동하며 좌표 출력
	void Move();

	// 랜덤한 이동 거리 생성
	int32 Step();

	// 이벤트 생성
	void createEvent(float Probability);
};

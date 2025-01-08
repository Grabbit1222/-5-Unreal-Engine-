// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HELLO_API AMyActor : public AActor
{
    GENERATED_BODY()

protected:
    // 시작점
    FVector2D Start;

public:
    // 생성자
    AMyActor();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // 매 프레임 호출 (사용 안 할 경우 비활성화)
    virtual void Tick(float DeltaTime) override;

    // Step 함수: 랜덤한 이동 거리 생성
    int32 Step();

    // Move 함수: 10회 이동하며 좌표 출력
    void Move();
};

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
    // ������
    FVector2D Start;

public:
    // ������
    AMyActor();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // �� ������ ȣ�� (��� �� �� ��� ��Ȱ��ȭ)
    virtual void Tick(float DeltaTime) override;

    // Step �Լ�: ������ �̵� �Ÿ� ����
    int32 Step();

    // Move �Լ�: 10ȸ �̵��ϸ� ��ǥ ���
    void Move();
};

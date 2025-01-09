// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class HELLO_API AMyActor2 : public AActor
{
    GENERATED_BODY()

protected:
    // ������
    FVector2D Start;

public:
    // ������
    AMyActor2();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // �� ������ ȣ�� (��� �� �� ��� ��Ȱ��ȭ)
    virtual void Tick(float DeltaTime) override;

    // Step �Լ�: ������ �̵� �Ÿ� ����
    int32 Step();

    // Move �Լ�: 10ȸ �̵��ϸ� ��ǥ ���
    void Move();
};

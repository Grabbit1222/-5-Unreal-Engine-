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
	// ������
	FVector2D Start;
	int32 evCnt;
	float totDist;

	int32 CurrentStep; // ���� �̵� �ܰ�
	FVector2D CurrentPosition; // ���� ��ġ
	FVector2D NewPosition; // �� ��ġ

public:	
	// Sets default values for this actor's properties
	AMyActor2();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �� ���� ������ �Ÿ�
	float distance(FVector2D first, FVector2D second);

	// 10ȸ �̵��ϸ� ��ǥ ���
	void Move();

	// ������ �̵� �Ÿ� ����
	int32 Step();

	// �̺�Ʈ ����
	void createEvent(float Probability);
};

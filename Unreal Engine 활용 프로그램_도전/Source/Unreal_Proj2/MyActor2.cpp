// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"
#include "Math/UnrealMathUtility.h" // FMath::RandRange�� ���� �ʿ�

// Sets default values: ������
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Tick enabled"));
	// ������ �ʱ�ȭ
	Start = FVector2D(0, 0);
}

// Step �Լ�: 0 �Ǵ� 1 ���� ��ȯ
int32 AMyActor2::Step() {
	return FMath::RandRange(0, 1);
}

// Move �Լ�: �����̱� ���� ���� �ʱ�ȭ
void AMyActor2::Move() {
	evCnt = 0;
	totDist = 0;

	CurrentStep = 0;
	CurrentPosition = Start;
	NewPosition = Start;

	// ������ġ ���
	UE_LOG(LogTemp, Warning, TEXT("Starting Position: (%f, %f)"), CurrentPosition.X, CurrentPosition.Y);
}

// distance �Լ�: �� ���� ������ �Ÿ� 
float AMyActor2::distance(FVector2D first, FVector2D second) {
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

void AMyActor2::createEvent(float Probability) {
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100�� ���� ����
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		evCnt++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
	}
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay called"));
	// Move �Լ� ȣ��
	Move();
	PrimaryActorTick.bCanEverTick = true; // Tick Ȱ��ȭ
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Tick called"));

	// X, Y �̵� �Ÿ� ����
	int32 XStep = Step();
	int32 YStep = Step();

	// ���� ��ġ ����
	NewPosition.X = CurrentPosition.X + XStep;
	NewPosition.Y = CurrentPosition.Y + YStep;

	// ���� ��ġ ���
	UE_LOG(LogTemp, Display, TEXT("Position after step %d: (%f, %f)"), CurrentStep + 1, NewPosition.X, NewPosition.Y);

	// �̵� �Ÿ� ���
	UE_LOG(LogTemp, Display, TEXT("Distance moved: %f"), distance(NewPosition, CurrentPosition));
	totDist += distance(NewPosition, CurrentPosition);

	// �̺�Ʈ �߻� ���� ���
	createEvent(50);

	// �� ��ġ �ֽ�ȭ
	CurrentPosition = NewPosition;
	CurrentStep++;

	// ��� �̵� �Ϸ� �� ó��
	if (CurrentStep >= 10) {
		UE_LOG(LogTemp, Warning, TEXT("Total distance: %f"), totDist);
		UE_LOG(LogTemp, Warning, TEXT("Total events triggered: %d"), evCnt);
		
		// ��������� Tick�� ��Ȱ��ȭ
		SetActorTickEnabled(false); // Tick ��Ȱ��ȭ
	}
}


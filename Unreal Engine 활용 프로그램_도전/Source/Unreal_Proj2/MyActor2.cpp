// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"
#include "Math/UnrealMathUtility.h" // FMath::RandRange를 위해 필요

// Sets default values: 생성자
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Tick enabled"));
	// 시작점 초기화
	Start = FVector2D(0, 0);
}

// Step 함수: 0 또는 1 랜덤 반환
int32 AMyActor2::Step() {
	return FMath::RandRange(0, 1);
}

// Move 함수: 움직이기 위한 변수 초기화
void AMyActor2::Move() {
	evCnt = 0;
	totDist = 0;

	CurrentStep = 0;
	CurrentPosition = Start;
	NewPosition = Start;

	// 시작위치 출력
	UE_LOG(LogTemp, Warning, TEXT("Starting Position: (%f, %f)"), CurrentPosition.X, CurrentPosition.Y);
}

// distance 함수: 두 벡터 사이의 거리 
float AMyActor2::distance(FVector2D first, FVector2D second) {
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

void AMyActor2::createEvent(float Probability) {
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
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
	// Move 함수 호출
	Move();
	PrimaryActorTick.bCanEverTick = true; // Tick 활성화
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Tick called"));

	// X, Y 이동 거리 생성
	int32 XStep = Step();
	int32 YStep = Step();

	// 현재 위치 갱신
	NewPosition.X = CurrentPosition.X + XStep;
	NewPosition.Y = CurrentPosition.Y + YStep;

	// 현재 위치 출력
	UE_LOG(LogTemp, Display, TEXT("Position after step %d: (%f, %f)"), CurrentStep + 1, NewPosition.X, NewPosition.Y);

	// 이동 거리 출력
	UE_LOG(LogTemp, Display, TEXT("Distance moved: %f"), distance(NewPosition, CurrentPosition));
	totDist += distance(NewPosition, CurrentPosition);

	// 이벤트 발생 여부 출력
	createEvent(50);

	// 현 위치 최신화
	CurrentPosition = NewPosition;
	CurrentStep++;

	// 모든 이동 완료 시 처리
	if (CurrentStep >= 10) {
		UE_LOG(LogTemp, Warning, TEXT("Total distance: %f"), totDist);
		UE_LOG(LogTemp, Warning, TEXT("Total events triggered: %d"), evCnt);
		
		// 명시적으로 Tick을 비활성화
		SetActorTickEnabled(false); // Tick 비활성화
	}
}


#include "MyActor.h"
#include "Math/UnrealMathUtility.h" // FMath::RandRange를 위해 필요

// 생성자
AMyActor::AMyActor()
{
    // Tick 함수 비활성화 (성능 최적화)
    PrimaryActorTick.bCanEverTick = false;

    // 시작점 초기화
    Start = FVector2D(0, 0);
}

// 스텝 함수: 0 또는 1을 랜덤 반환
int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1);
}

// 게임 시작 시 호출
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // Move 함수 호출
    Move();
}

// Move 함수: 랜덤으로 10회 이동하며 로그 출력
void AMyActor::Move()
{
    // 시작 위치 출력
    FVector2D CurrentPosition = Start;
    UE_LOG(LogTemp, Display, TEXT("Starting Position: (%f, %f)"), CurrentPosition.X, CurrentPosition.Y);

    for (int32 i = 0; i < 10; ++i)
    {
        // X, Y 이동 거리 생성
        int32 XStep = Step();
        int32 YStep = Step();

        // 이동 거리 제한 확인
        if (FMath::Abs(XStep) >= 2 || FMath::Abs(YStep) >= 2)
        {
            continue; // 제한 초과 시 이동하지 않음
        }

        // 현재 위치 갱신
        CurrentPosition.X += XStep;
        CurrentPosition.Y += YStep;

        // 현재 위치 출력
        UE_LOG(LogTemp, Display, TEXT("Position after step %d: (%f, %f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);
    }
}

// 매 프레임 호출 (현재 코드에서는 사용하지 않음)
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

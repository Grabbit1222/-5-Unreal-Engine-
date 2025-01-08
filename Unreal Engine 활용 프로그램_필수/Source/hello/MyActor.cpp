#include "MyActor.h"
#include "Math/UnrealMathUtility.h" // FMath::RandRange�� ���� �ʿ�

// ������
AMyActor::AMyActor()
{
    // Tick �Լ� ��Ȱ��ȭ (���� ����ȭ)
    PrimaryActorTick.bCanEverTick = false;

    // ������ �ʱ�ȭ
    Start = FVector2D(0, 0);
}

// ���� �Լ�: 0 �Ǵ� 1�� ���� ��ȯ
int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1);
}

// ���� ���� �� ȣ��
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // Move �Լ� ȣ��
    Move();
}

// Move �Լ�: �������� 10ȸ �̵��ϸ� �α� ���
void AMyActor::Move()
{
    // ���� ��ġ ���
    FVector2D CurrentPosition = Start;
    UE_LOG(LogTemp, Display, TEXT("Starting Position: (%f, %f)"), CurrentPosition.X, CurrentPosition.Y);

    for (int32 i = 0; i < 10; ++i)
    {
        // X, Y �̵� �Ÿ� ����
        int32 XStep = Step();
        int32 YStep = Step();

        // �̵� �Ÿ� ���� Ȯ��
        if (FMath::Abs(XStep) >= 2 || FMath::Abs(YStep) >= 2)
        {
            continue; // ���� �ʰ� �� �̵����� ����
        }

        // ���� ��ġ ����
        CurrentPosition.X += XStep;
        CurrentPosition.Y += YStep;

        // ���� ��ġ ���
        UE_LOG(LogTemp, Display, TEXT("Position after step %d: (%f, %f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);
    }
}

// �� ������ ȣ�� (���� �ڵ忡���� ������� ����)
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

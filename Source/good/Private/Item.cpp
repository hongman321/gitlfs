#include "Item.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"  // ConstructorHelpers �߰�

// �⺻ �� ����
AItem::AItem()
{
	// �� ���Ͱ� �� �����Ӹ��� Tick()�� ȣ���ϵ��� ����
	PrimaryActorTick.bCanEverTick = true;

	// ����ƽ �޽� ������Ʈ �ʱ�ȭ
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;  // ��Ʈ ������Ʈ�� ����

	// ����ƽ �޽��� ���� (�־��� ��ο��� �޽��� ã��)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrelMesh(TEXT("/Game/Cabin_Lake/Meshes/Barrel/SM_Barrel_01.SM_Barrel_01"));
	if (BarrelMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(BarrelMesh.Object);  // �޽��� ������Ʈ�� ����
	}
}

// ���� ���� �� �Ǵ� ���Ͱ� ������ �� ȣ��
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// �� �����Ӹ��� ȣ��
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ���� ��ġ ��������
	FVector CurrentLocation = GetActorLocation();

	// x ��ġ�� ������Ʈ�Ͽ� ���Ͱ� �̵��ϵ��� �ϱ� (DeltaTime�� ����Ͽ� ������ ���������� �̵�)
	float NewX = CurrentLocation.X + (Speed * MoveDirection * DeltaTime); // DeltaTime�� ���Ͽ� �ӵ��� ������ ���������� ����

	// x ��ġ�� MaxX�� ������ ������ �ٲٰ�, MinX ���Ϸ� �������� ������ �ٲ�
	if (NewX >= MaxX && MoveDirection > 0 || NewX <= MinX && MoveDirection < 0) // ���� ��ȯ ���� ����
	{
		MoveDirection *= -1;  // ���� ����
	}

	// ������Ʈ�� x ��ġ�� ���ο� ��ǥ ����
	SetActorLocation(FVector(NewX, CurrentLocation.Y, CurrentLocation.Z));
}

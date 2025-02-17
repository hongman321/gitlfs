#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class UStaticMeshComponent;  // UStaticMeshComponent Ŭ���� ����

// AItem Ŭ���� ����
UCLASS()
class GOOD_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// �⺻ �� ����
	AItem();

protected:
	// ���� ���� �� �Ǵ� ���Ͱ� ������ �� ȣ��
	virtual void BeginPlay() override;

public:
	// �� �����Ӹ��� ȣ��
	virtual void Tick(float DeltaTime) override;

	// ����ƽ �޽� ������Ʈ ����
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;  // ���Ϳ� ���� ����ƽ �޽� ������Ʈ

	// �̵� �ӵ� (�ʱⰪ�� 1000)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed = 1000.f;

	// �̵� ���� (�ִ�, �ּ� ��ġ)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinX = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxX = 1000.f;

	// �̵� ���� (1�̸� ������, -1�̸� �ڷ�)
	int32 MoveDirection = 1;
};

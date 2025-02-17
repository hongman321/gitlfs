#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class UStaticMeshComponent;  // UStaticMeshComponent 클래스 선언

// AItem 클래스 정의
UCLASS()
class GOOD_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// 기본 값 설정
	AItem();

protected:
	// 게임 시작 시 또는 액터가 생성될 때 호출
	virtual void BeginPlay() override;

public:
	// 매 프레임마다 호출
	virtual void Tick(float DeltaTime) override;

	// 스택틱 메쉬 컴포넌트 변수
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;  // 액터에 붙일 스택틱 메쉬 컴포넌트

	// 이동 속도 (초기값은 1000)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed = 1000.f;

	// 이동 범위 (최대, 최소 위치)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinX = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxX = 1000.f;

	// 이동 방향 (1이면 앞으로, -1이면 뒤로)
	int32 MoveDirection = 1;
};

#include "Item.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"  // ConstructorHelpers 추가

// 기본 값 설정
AItem::AItem()
{
	// 이 액터가 매 프레임마다 Tick()을 호출하도록 설정
	PrimaryActorTick.bCanEverTick = true;

	// 스택틱 메쉬 컴포넌트 초기화
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;  // 루트 컴포넌트로 설정

	// 스택틱 메쉬를 설정 (주어진 경로에서 메쉬를 찾음)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrelMesh(TEXT("/Game/Cabin_Lake/Meshes/Barrel/SM_Barrel_01.SM_Barrel_01"));
	if (BarrelMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(BarrelMesh.Object);  // 메쉬를 컴포넌트에 설정
	}
}

// 게임 시작 시 또는 액터가 생성될 때 호출
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// 매 프레임마다 호출
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재 위치 가져오기
	FVector CurrentLocation = GetActorLocation();

	// x 위치를 업데이트하여 액터가 이동하도록 하기 (DeltaTime을 사용하여 프레임 독립적으로 이동)
	float NewX = CurrentLocation.X + (Speed * MoveDirection * DeltaTime); // DeltaTime을 곱하여 속도를 프레임 독립적으로 유지

	// x 위치가 MaxX를 넘으면 방향을 바꾸고, MinX 이하로 내려가면 방향을 바꿈
	if (NewX >= MaxX && MoveDirection > 0 || NewX <= MinX && MoveDirection < 0) // 방향 전환 조건 수정
	{
		MoveDirection *= -1;  // 방향 반전
	}

	// 업데이트된 x 위치로 새로운 좌표 설정
	SetActorLocation(FVector(NewX, CurrentLocation.Y, CurrentLocation.Z));
}

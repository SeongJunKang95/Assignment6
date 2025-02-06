#include "NBC_B.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
ANBC_B::ANBC_B()
{
	// Scene Component를 생성하고 루트로 설정
	SceneRoot = CreateDefaultSubobject <USceneComponent>(TEXT("SceneRoot")); // Scene Component를 생성하고 루트로 설정
	SetRootComponent(SceneRoot);
	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Coin_A.SM_Coin_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset(TEXT("/Game/Resources/Materials/M_Coin_B.M_Coin_B"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 300.0f;
	MaxRange = 300.0f;
	bMovingForward = true;
}

	void ANBC_B::BeginPlay()
	{
		Super::BeginPlay();
		// 시작 위치 저장
		StartLocation = GetActorLocation();
	
	}
	void ANBC_B::Tick(float DeltaTime)

	{    

		Super::Tick(DeltaTime);
		// 현재 위치 가져오기
		FVector CurrentLocation = GetActorLocation();
		// 이동한 거리 계산
		float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

		// 최대 범위를 초과하면 방향 변경
		if (DistanceMoved >= MaxRange)
		{
			bMovingForward = !bMovingForward;
		}

		// 이동 방향 설정 ( 앞 또는 뒤로)
		float Direction = bMovingForward ? 1.0f : -1.0f;
		// 앞뒤 이동
		FVector NewLocation = CurrentLocation + FVector(0, Direction * MoveSpeed * DeltaTime,0);

		//위치 적용
		SetActorLocation(NewLocation);
    }

#include "NBC_A.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"



ANBC_A::ANBC_A()
{   
	

	// Scene Component를 생성하고 루트로 설정
	SceneRoot = CreateDefaultSubobject <USceneComponent>(TEXT("SceneRoot")); // Scene Component를 생성하고 루트로 설정
	SetRootComponent(SceneRoot);
	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//Static Mesh를 코드에서 설정
	//'/Game/Resources/Props/SM_Star_B.SM_Star_B'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	// Material을 코드에서 설정
	//'/Game/Resources/Materials/M_Mango.M_Mango'
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset(TEXT("/Game/Resources/Materials/M_Mango.M_Mango"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	
	// Tick 함수를 켜줍니다
	PrimaryActorTick.bCanEverTick = true;
	// 기본 회전 속도 ( 1초에 90도 회전)
	RotationSpeed = 90.0f;


}

void ANBC_A::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 45.0f, 0.0f));
	SetActorScale3D(FVector(2.0f));
	
	// 일정시간마다 위치 변경 (2초설정)
	GetWorld()->GetTimerManager().SetTimer(TimerHandler_ChangeLocation, this, &ANBC_A::ChangeLocation, 2.0f, true);
	// 일정 시간후 오브젝트 삭제 (30초설정)
	GetWorld()->GetTimerManager().SetTimer(TimerHandler_DestroyActer, this, &ANBC_A::DestroySelf, 30.0f, false);
	// 25초후 타이머 중지
	GetWorld()->GetTimerManager().SetTimer(TimerHandler_StopTimer, this, &ANBC_A::StopTimer, 25.0f, false);

}
// 위치 변경 함수
void ANBC_A::ChangeLocation()
{
	// 현재 위치 가져오기
	FVector CurrentLocation = GetActorLocation();

	// 랜덤한 방향으로 이동 (X, Y, Z 값 변경)
	float RandomX = FMath::RandRange(-300.0f, 300.0f);
	float RandomY = FMath::RandRange(-300.0f, 300.0f);
	float RandomZ = FMath::RandRange(-100.0f, 100.0f);

	FVector NewLocation = CurrentLocation + FVector(RandomX, RandomY, RandomZ);

	// 새로운 위치 적용
	SetActorLocation(NewLocation);
}

// 일정 시간이 지나면 오브젝트 제거
void ANBC_A::DestroySelf()
{
	Destroy();
}

// 25초 후 타이머 중지( 위치 변경 타이머가 중지)
void ANBC_A::StopTimer()
{
 GetWorld()->GetTimerManager().ClearTimer(TimerHandler_ChangeLocation);
}


void ANBC_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}


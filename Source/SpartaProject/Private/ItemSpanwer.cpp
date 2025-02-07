#include "ItemSpanwer.h"
#include "NBC_A.h"
#include "NBC_B.h"

AItemSpanwer::AItemSpanwer()
{
 
	PrimaryActorTick.bCanEverTick = false;

}


void AItemSpanwer::BeginPlay()
{
	Super::BeginPlay();
    //GetWorld()->SpawnActor<ANBC_A>(ItemClass, FVector(0, 0, 0), FRotator(0, 0, 0));

	//FMath::RandRange(-500.0f, 500.0f);

	// Getworld 가 NULL 이면 실행하지 않도록 체크 -> GetWorld()가 NULL이면 코드를 실행하지 않고 안전하게 종료.
	if (!GetWorld())
	{
		return;
	}

	for (int32 i = 0; i < 10; i++)
	{
		float RandomX = FMath::RandRange(-500.0f, 500.0f);
		float RandomY = FMath::RandRange(-500.0f, 500.0f);
		float RandomZ = FMath::RandRange(300.0f, 300.0f);

		FVector SpawnLocation(RandomX, RandomY, RandomZ);
		FRotator SpawnRotation(0.0f, 0.0f, 0.0f);
		
	
		if (NBC_A_Class) // NULL 체크후 객체 생성
		{
			GetWorld()->SpawnActor<ANBC_A>(NBC_A_Class, SpawnLocation, SpawnRotation);
		}
	}
	for (int32 i = 0; i < 20; i++)
	{
		float RandomX = FMath::RandRange(-500.0f, 500.0f);
		float RandomY = FMath::RandRange(-300.0f, 300.0f);
		float RandomZ = 100.0f;

		FVector SpawnLocation(RandomX, RandomY, RandomZ);
		FRotator SpawnRotation(0.0f, 0.0f, 0.0f);

		

		if (NBC_B_Class) // NULL 체크후 객체 생성 -> NULL 체크를 추가하면, NBC_A_Class 또는 NBC_B_Class가 설정되지 않았을 때 충돌을 방지할 수 있음.
		{
			GetWorld()->SpawnActor<ANBC_B>(NBC_B_Class, SpawnLocation, SpawnRotation);
		}
		

	}


}



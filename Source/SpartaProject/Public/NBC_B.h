#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBC_B.generated.h"

UCLASS()
class SPARTAPROJECT_API ANBC_B : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ANBC_B();

protected:
    virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	// 루트 컴포넌트를 나타내는 Scene Component 포인터 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NBC_A|Component") // 에디터에서 볼 수만 있고 수정 불가
		USceneComponent* SceneRoot;
	// Static Mesh Component 포인터
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NBC_B | Components")
	UStaticMeshComponent* StaticMeshComp;

	// 이동속도 (초당이동거리)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NBC_B|Properties")
	float MoveSpeed;
	// 최대 이동거리  ( 왕복 범위)
	UPROPERTY(EditAnywhere, Category = "NBC_B|Properties")
	float MaxRange;
	// 초기 위치 저장 변수
	FVector StartLocation;

	// 이동 방향 (true: 앞으로, false: 뒤로)
	bool bMovingForward;
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBC_A.generated.h"

UCLASS()
class SPARTAPROJECT_API ANBC_A : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ANBC_A();

protected:

    virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	// 루트 컴포넌트를 나타내는 Scene Component 포인터 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category = "NBC_A|Component") // 에디터에서 볼 수만 있고 수정 불가
	USceneComponent* SceneRoot;
	// Static Mesh Component 포인터
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "NBC_A|Component")// 에디터또는 블루프린터에서 수정 가능
	UStaticMeshComponent* StaticMeshComp;
    // 회전 속도를 나타내는 변수
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,  Category = "NBC_A|Properties") // 회전속도, 클래스 기본값만 수정 가능
	float RotationSpeed;
	
	// FTimerHandle 선언
	// 위치 변경 타이머 핸들러
	FTimerHandle TimerHandler_ChangeLocation;
	// 오브젝트 삭제 타이머 핸들러
	FTimerHandle TimerHandler_DestroyActer;

	// 타이머 중지 타이머 핸들러
	FTimerHandle TimerHandler_StopTimer;

	// 일정시간이 지나면 오브젝트 제거
	void DestroySelf();

	// 위치 변경 함수
	void ChangeLocation();

	// 타이머 중지 함수
	void StopTimer();
};

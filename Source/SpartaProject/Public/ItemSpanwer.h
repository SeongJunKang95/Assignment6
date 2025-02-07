#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBC_A.h"
#include "NBC_B.h"
#include "ItemSpanwer.generated.h"

UCLASS()
class SPARTAPROJECT_API AItemSpanwer : public AActor
{
	GENERATED_BODY()

public:

	AItemSpanwer();

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<ANBC_A> NBC_A_Class;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<ANBC_B> NBC_B_Class;

protected:


	virtual void BeginPlay() override;

};
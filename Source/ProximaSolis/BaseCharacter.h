// Copyright 2POW6 Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RPGComponent.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

#pragma region(USTRUCTS)
USTRUCT(BlueprintType)
struct PROXIMASOLIS_API FPlayerInfo
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
		FString PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
		int32 PlayerLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
		float PlayerXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
		float PlayerMaxXp;
};
#pragma endregion

UCLASS()
class PROXIMASOLIS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	/** Characters' attributes.*/
	UPROPERTY(BlueprintReadWrite, Category = "Attributes")
		URPGComponent* Attributes;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

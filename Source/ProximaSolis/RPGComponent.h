// Copyright 2POW6 Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/ActorComponent.h"
#include "RPGComponent.generated.h"

class UUserWidget;

#pragma region(Attributes Enum)

/**Base Attributes for all characters. */
UENUM(BlueprintType)
enum class EAttributes : uint8
{
	None UMETA(DisplayName = "None"),
	Health UMETA(DisplayName = "Health"),
	Experience UMETA(DisplayName = "Experience"),
	Level UMETA(DisplayName = "Level"),
	Weapon UMETA(DisplayName = "Weapon"),
	Armor UMETA(DisplayName = "Armor")
};

/** Base attributes for all characters in game. */
USTRUCT(BlueprintType)
struct PROXIMASOLIS_API FAttributesData
{
	GENERATED_USTRUCT_BODY()
		
	FAttributesData()
		: MaxValue(100.f)
		, CurrentValue(MaxValue)
		, Modifier(1)
	{}

	FAttributesData(float DefaultValue)
		: MaxValue(DefaultValue)
		, CurrentValue(MaxValue)
		, Modifier(1)
	{}

	/** Getter for max value */
	float GetMaxValue() const;
	/** Getter for current value */
	float GetCurrentValue() const;
	/** Getter for modifier */
	float GetModifier() const;
	/** Setter for max value */
	virtual void SetMaxValue(const float NewValue);
	/** Setter for current value */
	virtual void SetCurrentValue(const float NewValue);
	/** Setter for modifier */
	virtual void SetModifier(const float NewValue);

	/** Attributes :*/
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
		float MaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
		float CurrentValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
		float Modifier;
};
#pragma endregion

UCLASS()
class PROXIMASOLIS_API UAttributesDataFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/* Getters */

	/** Blueprint Function to return the value of MaxValue from the struct
	@Params AttributesData value to get from the struct*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Getter")
		static float GetMaxValue(UPARAM(ref) FAttributesData& AttributesData) { return AttributesData.GetMaxValue(); }
	/** Blueprint Function to return the value of CurrentValue from the struct
	@Params AttributesData value to get from the struct*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Getter")
		static float GetCurrentValue(UPARAM(ref) FAttributesData& AttributesData) { return AttributesData.GetCurrentValue(); }
	/** Blueprint Function to return the value of Modifier from the struct
	@Params AttributesData value to get from the struct*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Getter")
		static int32 GetModifier(UPARAM(ref) FAttributesData& AttributesData) { return AttributesData.GetModifier(); }

	/* Setters */

	/** Blueprint Function to set the value of MaxValue from the struct
	@Params AttributesData & value to set in the struct */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Setter")
		static void SetMaxValue(UPARAM(ref) FAttributesData& AttributesData, const float Value) { AttributesData.SetMaxValue(Value); }
	/** Blueprint Function to set the value of CurrentValue from the struct
	@Params AttributesData & value to set in the struct */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Setter")
		static void SetCurrentValue(UPARAM(ref) FAttributesData& AttributesData, const float Value) { AttributesData.SetCurrentValue(Value); }
	/** Blueprint Function to set the value of Modifier from the struct
	@Params AttributesData & value to set in the struct */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Setter")
		static void SetModifier(UPARAM(ref) FAttributesData& AttributesData, const float Value) { AttributesData.SetModifier(Value); }
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROXIMASOLIS_API URPGComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URPGComponent();

	/** health attribute for the character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		FAttributesData Health;
	/** Experience attribute for the character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		FAttributesData Experience;
	/** Level attribute for the character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		FAttributesData Level;
	/** Weapon attribute for the character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		FAttributesData Weapon;
	/** Armor attribute for the character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		FAttributesData Armor;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/** Check if leveled up*/
	UFUNCTION(BlueprintCallable)
		void CheckLevelUp();

	/** Level Up function*/
	UFUNCTION(BlueprintCallable)
		void LevelUp();

	/** Do a full heal (when resting or gaining a level)*/
	UFUNCTION(BlueprintCallable)
		void FullHeal();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bIsLevelUp = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	/** Check if we can add a level, then call it when gaining XP.*/
	UFUNCTION(BlueprintCallable)
		void GainExperience(float XpValue);

};

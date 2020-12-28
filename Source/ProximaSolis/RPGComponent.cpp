// Copyright 2POW6 Games. All Rights Reserved.


#include "RPGComponent.h"
#include "UMG/Public/Blueprint/UserWidget.h"

// Sets default values for this component's properties
URPGComponent::URPGComponent()
	: Health()
	, Experience(0.f)
	, Level(1.f)
	, Weapon(5.f)
	, Armor(25.f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URPGComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void URPGComponent::CheckLevelUp()
{
	if (Experience.GetCurrentValue() >= Experience.GetMaxValue())
	{
		float XpSurplus = Experience.GetCurrentValue() - Experience.GetMaxValue();
		Experience.SetCurrentValue(0);
		Experience.SetMaxValue(Experience.GetMaxValue() * 1.05f);
		LevelUp();
		GainExperience(XpSurplus);
	}
}


void URPGComponent::LevelUp()
{
	if (Level.GetCurrentValue() + 1.f != Level.GetMaxValue())
	{
		Level.SetCurrentValue(Level.GetCurrentValue() + 1);
		FullHeal();
	}
}

void URPGComponent::FullHeal()
{
	Health.SetCurrentValue(Health.GetMaxValue());
}

// Called every frame
void URPGComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URPGComponent::GainExperience(float XpValue)
{
	Experience.SetCurrentValue(Experience.GetCurrentValue() + XpValue);
	CheckLevelUp();
}

float FAttributesData::GetMaxValue() const
{
	return FAttributesData::MaxValue;
}

float FAttributesData::GetCurrentValue() const
{
	return FAttributesData::CurrentValue;
}

float FAttributesData::GetModifier() const
{
	return FAttributesData::Modifier;
}

void FAttributesData::SetMaxValue(const float NewValue)
{
	FAttributesData::MaxValue = NewValue;
}

void FAttributesData::SetCurrentValue(const float NewValue)
{
	FAttributesData::CurrentValue = NewValue;
}

void FAttributesData::SetModifier(const float NewValue)
{
	FAttributesData::Modifier = NewValue;
}

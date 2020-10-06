#pragma once

#include <Runtime/Core/Public/CoreMinimal.h>
#include <Runtime/CoreUObject/Public/UObject/ObjectMacros.h>
#include <Runtime/Engine/Classes/GameFramework/Volume.h>

#include "ParticleCullVolume.generated.h"

UCLASS(MinimalAPI)
class AParticleCullVolume : public AVolume
{
	GENERATED_BODY()

public:

	AParticleCullVolume(const FObjectInitializer& ObjectInitialiser);

	UPROPERTY(EditInstanceOnly)
	TArray<FString> EmitterFlagsToCull;
};
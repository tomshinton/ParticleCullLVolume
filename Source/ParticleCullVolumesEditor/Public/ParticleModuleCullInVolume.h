#pragma once

#include <Runtime/Core/Public/CoreMinimal.h>
#include <Runtime/CoreUObject/Public/CoreUObject.h>

#include <ParticleCullVolumes/Public/ParticleCullVolume.h>
#include <Runtime/Engine/Public/ParticleEmitterInstances.h>
#include <Runtime/Engine/Classes/Particles/Color/ParticleModuleColorBase.h>
#include <Runtime/Engine/Classes/Particles/ParticleSystemComponent.h>

#include "ParticleModuleCullInVolume.generated.h"

UCLASS(editinlinenew, hidecategories = Object, MinimalAPI, meta = (DisplayName = "Cull In Volume"))
class UParticleModuleCullInVolume : public UParticleModuleColorBase
{
	GENERATED_BODY()

	UParticleModuleCullInVolume(const FObjectInitializer& ObjectInitialiser)
	: Super(ObjectInitialiser)
	, BlendStartDistance(100.f)
	{
		bUpdateModule = true;
	}

	void Update(FParticleEmitterInstance* Owner, int32 Offset, float DeltaTime) override
	{
		Super::Update(Owner, Offset, DeltaTime);

		if (BlendStartDistance > 0.f)
		{
			if (UWorld* World = Owner->Component->GetWorld())
			{
				for (TObjectIterator<AParticleCullVolume> Itr; Itr; ++Itr)
				{
					if (AParticleCullVolume* CullVolume = *Itr)
					{
						if (CullVolume->EmitterFlagsToCull.Contains(CullFlag))
						{
							if (CullVolume->GetBrushComponent() != nullptr)
							{
				BEGIN_UPDATE_LOOP;
								float OutDistanceToPoint;
								CullVolume->EncompassesPoint(Particle.Location, 0.f, &OutDistanceToPoint);

								if (OutDistanceToPoint >= 0.f)
								{
									if (FMath::IsWithin(OutDistanceToPoint, 0.f, BlendStartDistance))
									{
										const float NormalisedBlend = FMath::Clamp(OutDistanceToPoint / BlendStartDistance, 0.f, 1.f);
										Particle.Color = FLinearColor(Particle.Color.R, Particle.Color.G, Particle.Color.B, Particle.Color.B * NormalisedBlend);
									}
								}
				END_UPDATE_LOOP;
							}
						}
					}
				}
			}
		}
	}

	UPROPERTY(EditAnywhere, Category = Color)
	float BlendStartDistance;

	UPROPERTY(EditAnywhere, Category = Color)
	FString CullFlag;
};
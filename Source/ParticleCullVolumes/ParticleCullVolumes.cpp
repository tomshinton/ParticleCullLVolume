// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include <Runtime/Core/Public/CoreMinimal.h>
#include <Runtime/Core/Public/Modules/ModuleManager.h>

DEFINE_LOG_CATEGORY_STATIC(ParticleCullVolumeLog, Log, All)

class FParticleCullVolumesModule : public IModuleInterface
{
public:

	virtual void StartupModule() override
	{
		UE_LOG(ParticleCullVolumeLog, Log, TEXT("Spinning up ParticleCullVolume module"))
	};

	virtual void ShutdownModule() override
	{
		UE_LOG(ParticleCullVolumeLog, Log, TEXT("Shutting down ParticleCullVolume module"))
	};
};

IMPLEMENT_MODULE(FParticleCullVolumesModule, ParticleCullVolumes)
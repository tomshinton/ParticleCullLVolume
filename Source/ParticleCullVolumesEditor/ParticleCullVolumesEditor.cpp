// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include <Runtime/Core/Public/CoreMinimal.h>
#include <Runtime/Core/Public/Modules/ModuleManager.h>

DEFINE_LOG_CATEGORY_STATIC(ParticleCullVolumesEditorLog, Log, All)

class FParticleCullVolumesEditorModule : public IModuleInterface
{
public:

	virtual void StartupModule() override
	{
		UE_LOG(ParticleCullVolumesEditorLog, Log, TEXT("Spinning up ParticleCullVolumeEditor module"));
	};

	virtual void ShutdownModule() override
	{
		UE_LOG(ParticleCullVolumesEditorLog, Log, TEXT("Shutting down ParticleCullVolumeEditor module"));
	}
};

IMPLEMENT_MODULE(FParticleCullVolumesEditorModule, ParticleCullVolumesEditor)
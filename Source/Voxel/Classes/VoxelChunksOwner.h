// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "VoxelChunksOwner.generated.h"

UCLASS()
class VOXEL_API AVoxelChunksOwner : public AActor
{
	GENERATED_BODY()

public:
	AVoxelChunksOwner()
	{
		auto TouchCapsule = CreateDefaultSubobject<UCapsuleComponent>(FName("Capsule"));
		TouchCapsule->InitCapsuleSize(0.1f, 0.1f);
		TouchCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		TouchCapsule->SetCollisionResponseToAllChannels(ECR_Ignore);
		RootComponent = TouchCapsule;
	}
};
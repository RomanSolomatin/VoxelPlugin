// Copyright 2017 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelMaterial.h"
#include "VoxelAsset.h"
#include "BufferArchive.h"
#include "MemoryReader.h"
#include "VoxelDataAsset.generated.h"

// 0, 0, 0 is the center
struct VOXEL_API FDecompressedVoxelDataAsset : FDecompressedVoxelAsset
{
	int32 SizeX;
	int32 SizeY;
	int32 SizeZ;

	TArray<float> Values;
	TArray<FVoxelMaterial> Materials;

	TArray<uint8> VoxelTypes;

	// Warning: Doesn't initialize values
	void SetSize(int32 NewSizeX, int32 NewSizeY, int32 NewSizeZ);

	float GetValue(const int X, const int Y, const int Z) override;
	FVoxelMaterial GetMaterial(const int X, const int Y, const int Z) override;
	EVoxelType GetVoxelType(const int X, const int Y, const int Z) override;
	FVoxelBox GetBounds() override;

	void SetValue(const int X, const int Y, const int Z, const float NewValue);
	void SetMaterial(const int X, const int Y, const int Z, const FVoxelMaterial NewMaterial);
	void SetVoxelType(const int X, const int Y, const int Z, const EVoxelType VoxelType);
};

FORCEINLINE FArchive& operator<<(FArchive &Ar, FDecompressedVoxelDataAsset& Asset)
{
	Ar << Asset.SizeX;
	Ar << Asset.SizeY;
	Ar << Asset.SizeZ;

	Ar << Asset.Values;
	Ar << Asset.Materials;

	Ar << Asset.VoxelTypes;

	return Ar;
}


UCLASS(MinimalAPI)
class UVoxelDataAsset : public UVoxelAsset
{
	GENERATED_BODY()

public:
	UVoxelDataAsset(const FObjectInitializer& ObjectInitializer);

	bool GetDecompressedAsset(FDecompressedVoxelAsset*& Asset, const float VoxelSize) override;

protected:
	void AddAssetToArchive(FBufferArchive& ToBinary, FDecompressedVoxelAsset* Asset) override;
	void GetAssetFromArchive(FMemoryReader& FromBinary, FDecompressedVoxelAsset* Asset) override;
};
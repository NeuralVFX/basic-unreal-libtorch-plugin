// Copyright 2020 NeuralVFX, Inc. All Rights Reserved.

#include "LibTorchViewer.h"
#include "cDataStorageGameInstance.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h" 
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Texture2D.h"


ALibTorchViewer::ALibTorchViewer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create and Set Plane Mesh Component
	PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	PlaneMesh->SetStaticMesh(MeshAsset.Object);

	// Fetch LibTorch Material From Scene
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/LibTorchPlugin/LibTorchMaterial.LibTorchMaterial'"));
	PlaneMesh->SetMaterial(0, MaterialAsset.Object);
}


void ALibTorchViewer::BeginPlay()
{
	// Start Camera
	Super::BeginPlay();

	// Make Material Instance
	UMaterialInstance * Material = (UMaterialInstance *)PlaneMesh->GetMaterial(0);
	MasterMaterialRef = Material;
}


void ALibTorchViewer::Tick(float DeltaTime)
{
	// Open GameInstance
	UcDataStorageGameInstance * GameInst = (UcDataStorageGameInstance*)GetGameInstance();

	// Get Image Data From LibTorch Model 
	TArray<unsigned char, TFixedAllocator<512 * 512 * 4>> Image;
	Image.SetNumZeroed(512 * 512 * 4);
	GameInst->GetImage(Image.GetData());

	// Make Texture and Set with LibTorch Result
	UMaterialInstanceDynamic* MatInst = UMaterialInstanceDynamic::Create(MasterMaterialRef, this);
	UTexture2D* Texture = UTexture2D::CreateTransient(512, 512, PF_B8G8R8A8);
	FTexture2DMipMap& Mip = Texture->PlatformData->Mips[0];
	void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(Data, Image.GetData(), 512 * 512 * 4);
	Mip.BulkData.Unlock();

	// Place Texture Into Material Parameter
	Texture->UpdateResource();
	MatInst->SetTextureParameterValue(FName("LibTorchInput"), (UTexture*)Texture);

	// Set Material
	PlaneMesh->SetMaterial(0, MatInst);

	Super::Tick(DeltaTime);
}


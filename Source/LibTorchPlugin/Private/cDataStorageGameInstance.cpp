// Copyright 2020 NeuralVFX, Inc. All Rights Reserved.

#include "cDataStorageGameInstance.h"
#include "cDataStorageWrapper.h"


void UcDataStorageGameInstance::Init()
{
	// Init DLL
	Super::Init();
	if (ImportDataStorageLibrary())
	{
		UE_LOG(LogTemp, Log, TEXT("LibTorch DLL Loaded"));

	}
}


bool UcDataStorageGameInstance::ImportDataStorageLibrary()
{
	// Import the DLL and Load Functions
	m_refDataStorageUtil = NewObject<UcDataStorageWrapper>(this);
	if (m_refDataStorageUtil == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not Create the Data Storage Object"));
		return false;
	}

	if (!m_refDataStorageUtil->ImportDLL("basic-unreal-libtorch-plugin", "export_wrapper.dll"))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Import DLL"));
		return false;
	}
	if (!m_refDataStorageUtil->ImportMethods())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Import DLL Methods"));
		return false;
	}
	return true;
}


void UcDataStorageGameInstance::Shutdown()
{
	// Calls DLL Function to ShutDown Camera
	m_refDataStorageUtil->CallCloseCV();
	Super::Shutdown();
	UE_LOG(LogTemp, Error, TEXT("Release Camera"))
}


void UcDataStorageGameInstance::OnStart()
{
	// Calls DLL Function to Activate Camera
	m_refDataStorageUtil->CallInitCV();
	UE_LOG(LogTemp, Log, TEXT("Opened Camera"));
	Super::OnStart();
}


void UcDataStorageGameInstance::GetImage(unsigned char* image)
{
	// Calls DLL Function to Run LibTorch Model and Return Image
	m_refDataStorageUtil->CallGetImageCV(image);
	UE_LOG(LogTemp, Log, TEXT("CV Image Raad"));
}


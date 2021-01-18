// Copyright 2020 NeuralVFX, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "cDataStorageGameInstance.generated.h"

/** Game Instance which is responsible for loading and calling DLL wrapper */
UCLASS()
class LIBTORCHPLUGIN_API UcDataStorageGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:

	/** Storage for DLL object */
	UPROPERTY()
	class UcDataStorageWrapper* m_refDataStorageUtil;

	/**
	* Attempt to import DLL and all of its functions.
	* @return Whether the operation is succesfull.
	*/
	bool ImportDataStorageLibrary();

public:

	/**
	* Overridden to import DLL and DLL functions on Init.
	*/
	virtual void Init() override;

	/**
	* Overridden to open the camera with OpenCV.
	*/
	virtual void OnStart() override;

	/**
	* Overridden to close the camera with OpenCV.
	*/
	virtual void Shutdown() override;

	/**
	* Runs neural net on camera frame, then returns the result.
	* @param image - Raw image pointer to return information from DLL.
	*/
	void GetImage(unsigned char* image);

};

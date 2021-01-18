// Copyright 2020 NeuralVFX, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "cDataStorageWrapper.generated.h"

typedef bool(*__Init)();
typedef void(*__Close)();
typedef bool(*__GetImage)(unsigned char* image);

/** Wrapper for external DLL, allows the executing of the neural net and passes the data back to Unreal */
UCLASS()
class LIBTORCHPLUGIN_API UcDataStorageWrapper : public UObject
{
	GENERATED_BODY()
private:

	/** DLL Handle */
	void *v_dllHandle;

	/** DLL Functions */
	__Init m_funcInitCV;
	__Close m_funcCloseCV;
	__GetImage m_funcGetImageCV;


public:

	/**
	* Attempt to import DLL.
	* @param a_strFolderName -  Folder of DLL.
	* @param a_strDLLName - Name of DLL file.
	* @return Whether the operation is succesfull.
	*/
	bool ImportDLL(FString a_strFolderName, FString a_strDLLName);

	/**
	* Attempt to import all functions of the DLL.
	* @return Whether the operation is succesfull.
	*/
	bool ImportMethods();

	/**
	* Open the camera with OpenCV.
	*/
	void CallInitCV();

	/**
	* Close the camera with OpenCV.
	*/
	void CallCloseCV();

	/**
	* Runs neural net on camera frame, then returns the result.
	* @param image - Raw image pointer to return information from DLL.
	*/
	void CallGetImageCV(unsigned char* image);
};







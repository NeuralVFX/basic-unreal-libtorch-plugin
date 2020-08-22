// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "cDataStorageWrapper.generated.h"

/**
 *
 */

//
typedef bool(*__Init)();
typedef void(*__Close)();
typedef bool(*__GetImage)(unsigned char* image);


UCLASS()
class LIBTORCHPLUGIN_API UcDataStorageWrapper : public UObject
{
	GENERATED_BODY()
private:

	// DLL Handle
	void *v_dllHandle;

	// FDLL unctions
	__Init m_funcInitCV;
	__Close m_funcCloseCV;
	__GetImage m_funcGetImageCV;


public:

		bool ImportDLL(FString a_strFolderName, FString a_strDLLName);

		bool ImportMethods();

		int CallInitCV();

		int CallCloseCV();

		int CallGetImageCV(unsigned char* image);
};







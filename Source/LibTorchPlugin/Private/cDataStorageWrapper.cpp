#include "cDataStorageWrapper.h"
#include "Paths.h"


bool UcDataStorageWrapper::ImportDLL(FString FolderName, FString DLLName)
{
	// Init DLL from a Path
	FString FilePath = *FPaths::GamePluginsDir() + FolderName + "/" + DLLName;
	if (FPaths::FileExists(FilePath))
	{
		v_dllHandle = FPlatformProcess::GetDllHandle(*FilePath);
		if (v_dllHandle != NULL)
		{
			return true;
		}
	}
	return false;
}


bool UcDataStorageWrapper::ImportMethods()
{
	// Loop Through and Import All Functions from DLL   --   Make Sure proc_name matches name of DLL method
	if (v_dllHandle != NULL)
	{
		FString ProcName = "InitNet";
		m_funcInitCV = (__Init)FPlatformProcess::GetDllExport(v_dllHandle, *ProcName);
		if (m_funcInitCV == NULL)
		{
			return false;
		}
		ProcName = "CloseNet";
		m_funcCloseCV = (__Close)FPlatformProcess::GetDllExport(v_dllHandle, *ProcName);
		if (m_funcCloseCV == NULL)
		{
			return false;
		}
		ProcName = "GetImage";
		m_funcGetImageCV = (__GetImage)FPlatformProcess::GetDllExport(v_dllHandle, *ProcName);
		if (m_funcGetImageCV == NULL)
		{
			return false;
		}
	}
	return true;
}


int UcDataStorageWrapper::CallInitCV()
{
	// Calls DLL Function to Activate Camera
	if (m_funcInitCV == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Function Not Loaded From DLL: InitNet"));
		return INT_MIN;
	}
	bool init = m_funcInitCV();
	UE_LOG(LogTemp, Error, TEXT("OpenCV Connection Opened %s"), init ? "true" : "false");
	return 1;
}


int UcDataStorageWrapper::CallCloseCV()
{
	// Calls DLL Function to ShutDown Camera
	if (m_funcCloseCV == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Function Not Loaded From DLL: CloseNet"));
		return INT_MIN;
	}
	m_funcCloseCV();
	UE_LOG(LogTemp, Error, TEXT("OpenCV Connection Close"));
	return 1;
}


int UcDataStorageWrapper::CallGetImageCV(unsigned char* Image)
{
	// Calls DLL Function to Run LibTorch Model and Return Image
	if (m_funcGetImageCV == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Function Not Loaded From DLL: Get Image "));
		return INT_MIN;
	}

	bool GetImage = m_funcGetImageCV(Image);

	if (GetImage == false)
	{
		UE_LOG(LogTemp, Error, TEXT("OpenCV Image Could Not Be Loaded"));

	}
	return 1;
}

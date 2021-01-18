// Fill out your copyright notice in the Description page of Project Settings.

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

	UPROPERTY()
	class UcDataStorageWrapper* m_refDataStorageUtil;

	bool ImportDataStorageLibrary();

public:

	virtual void Init() override;

	virtual void OnStart() override;

	virtual void Shutdown() override;

	void GetImage(unsigned char* image);

};

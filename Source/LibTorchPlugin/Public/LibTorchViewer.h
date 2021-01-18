// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LibTorchViewer.generated.h"

/** Just a plane mesh which displays the output of the neural net as an animated texture */
UCLASS()
class LIBTORCHPLUGIN_API ALibTorchViewer : public AActor
{
	GENERATED_BODY()
	
public:

	ALibTorchViewer();

	/** Mesh to Render Texture On */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output Settings")
	class UStaticMeshComponent* PlaneMesh;

	/** Material to Override Texture On */
	UPROPERTY(EditDefaultsOnly, Category = Materials)
	class UMaterialInstance * MasterMaterialRef;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;


	
	
};


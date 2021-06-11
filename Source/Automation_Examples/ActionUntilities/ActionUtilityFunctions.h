// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "Sound/SoundWave.h"
#include "Engine/Texture.h"
#include  "Blueprint/UserWidget.h"
#include "Animation/MorphTarget.h"
#include "Components/SkeletalMeshComponent.h"




#include "ActionUtilityFunctions.generated.h"

/**
 * 
 */
UCLASS()

class AUTOMATION_EXAMPLES_API UActionUtilityFunctions : public UAssetActionUtility
{
	GENERATED_BODY()
	
	public:
	UFUNCTION(CallInEditor)
	void AssetDuplicator(uint32 numberofduplicates = 1, bool bSave = true);
	 
	UFUNCTION(CallInEditor)
	void CleanUp(FString parentfolder=FString("/Game"));

	UFUNCTION(CallInEditor)
	void AddPrefixes();

	UFUNCTION(CallInEditor)
	void RenameSelectedAssets(FString searchphrase, FString replacementphrase, ESearchCase::Type searchcase);

	UFUNCTION(CallInEditor)
	void CheckPowerofTwo();

	private: 

	// like a dictionary in Python. TMaps hold key, values. 
	const TMap<UClass*, FString> PrefixMap= 
	{
	{UBlueprint::StaticClass(),TEXT("BP_")},
	{UStaticMesh::StaticClass(),TEXT("SM_")},
	{UMaterial::StaticClass(),TEXT("M_")},
	{UMaterialInstance::StaticClass(),TEXT("MI_")},
	{UMaterialFunction::StaticClass(),TEXT("MF_")},
	{UParticleSystem::StaticClass(),TEXT("PS_")},
	{USoundCue::StaticClass(),TEXT("SC_")},
	{USoundWave::StaticClass(),TEXT("SW_")},
	{UTexture::StaticClass(),TEXT("T_")},
	{UTexture2D::StaticClass(),TEXT("T_")},
	{UUserWidget::StaticClass(),TEXT("UW_")}, // <--This requires a special module added to the build file.<<<<
	{UMorphTarget::StaticClass(),TEXT("MT_")},
	{USkeletalMeshComponent::StaticClass(),TEXT("SK_")}
	};

	bool IsPowerOfTwo(int32 numbertocheck);
	// this function is a shortcut to display on screen debug message.
	void Display(FString string, FColor color);
	// this function  takes a string and appends two values to it. 
	void GiveFeedback(FString string, uint32 counter);

};

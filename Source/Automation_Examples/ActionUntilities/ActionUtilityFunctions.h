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
	void AddPrefixes();
	UFUNCTION(CallInEditor)
	void RenameSelectedAssets(FString searchphrase, FString replacementphrase, ESearchCase::Type searchcase);
	UFUNCTION(CallInEditor)
	void CheckPowerofTwo();

	private: 
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
	{UUserWidget::StaticClass(),TEXT("UW_")},
	{UMorphTarget::StaticClass(),TEXT("MT_")},
	{USkeletalMeshComponent::StaticClass(),TEXT("SK_")}
	};





	

	bool IsPowerOfTwo(int32 numbertocheck);
	void Display(FString string, FColor color);
	void GiveFeedback(FString string, uint32 counter);

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
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
	void RenameSelectedAssets(FString searchphrase, FString replacementphrase, ESearchCase::Type searchcase);
	UFUNCTION(CallInEditor)
	void CheckPowerofTwo();

	private: 
	bool IsPowerOfTwo(int32 numbertocheck);
	void Display(FString string, FColor color);
	void GiveFeedback(FString string, uint32 counter);

};

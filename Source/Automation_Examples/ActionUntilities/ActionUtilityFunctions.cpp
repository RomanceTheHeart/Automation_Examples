// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionUtilityFunctions.h"
#include "EditorUtilityLibrary.h"
#include "Engine/Texture.h"



void UActionUtilityFunctions::AddPrefixes()
{
TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
uint32 Counter{0}; 
for (UObject* selectedobjects : SelectedObjects)
{
	if (ensure(selectedobjects))
	{
		const FString* Prefix = PrefixMap.Find(selectedobjects->GetClass()); 
		if(ensure(Prefix) && !Prefix->Equals(""))
		{
			FString OldName = selectedobjects->GetName();
			if (!OldName.StartsWith(*Prefix))
			{
				FString NewName = *Prefix + OldName; 
				UEditorUtilityLibrary::RenameAsset(selectedobjects,NewName); 
				Counter++;

			}
		}
		else {Display("Couldn't find prefix for class ", FColor::Red); }
	}
}

}

#pragma region RenameAssets
void UActionUtilityFunctions::RenameSelectedAssets(FString searchphrase, FString replacementphrase, ESearchCase::Type searchcase)
{
	if (searchphrase.IsEmpty() || searchphrase.Equals(replacementphrase, searchcase)) { return; }
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 Counter{ 0 };
	for (UObject* selectedobject : SelectedObjects)
	{
		if (!selectedobject) { return; }

		FString AssetName = selectedobject->GetName();
		if (AssetName.Contains(searchphrase, searchcase))
		{
			FString NewName = AssetName.Replace(*searchphrase, *replacementphrase, searchcase);
			UEditorUtilityLibrary::RenameAsset(selectedobject, NewName);
			Counter++;
		GiveFeedback(TEXT(" Renamed "),Counter);
		}

	}
}
#pragma endregion RenameAssets


#pragma region CheckPowerofTwo

void UActionUtilityFunctions::CheckPowerofTwo()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0, FColor::Black, (TEXT("POWER OF TWO JUST RAN!")));
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 Counter{ 0 };

	for (UObject* selectedobject : SelectedObjects)
	{
		if (!selectedobject) { return; }

		UTexture* Texture = dynamic_cast<UTexture*>(selectedobject);
		if (!Texture) { return; }
		if (Texture) {
			int32 Width = static_cast<int32>(Texture->GetSurfaceWidth());
			int32 Height = static_cast<int32>(Texture->GetSurfaceHeight());
			if (!IsPowerOfTwo(Width) || !IsPowerOfTwo(Height))
			{

				GEngine->AddOnScreenDebugMessage(-1, 3.0, FColor::Black, (TEXT("%s "), selectedobject->GetName() + " is a Power of two."));
			}
			else
			{
				++Counter;
				GEngine->AddOnScreenDebugMessage(-1, 3.0, FColor::Black, (TEXT("%s "), selectedobject->GetName() + " not is a Power of two."));

			}

		}

		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0, FColor::Black, (TEXT("%s "), selectedobject->GetName() + " is not a selected texture"));
		}


	}
}

bool UActionUtilityFunctions::IsPowerOfTwo(int32 numbertocheck)
{
	while (numbertocheck % 2 == 0)
	{
		numbertocheck = numbertocheck / 2;
		if (numbertocheck % 2 != 0 && numbertocheck != 1) { return true; }

	}
	return false;
	// This is just a test. 
}
#pragma endregion CheckPowerofTwo

#pragma region PrivateFunctions
void UActionUtilityFunctions::Display(FString string, FColor color)
{
GEngine->AddOnScreenDebugMessage(-1,3.0f,color,string);
}

void UActionUtilityFunctions::GiveFeedback(FString string, uint32 counter)
{

FString message = FString(" No matching files found. ");
FColor color = (counter > 0 ? FColor::Green : FColor::Red);
if (counter > 0)
{
	message = string.AppendChar(' ');
	message.AppendInt(counter); 
	message.Append(counter == 1 ? TEXT(" file "): TEXT(" files ")); 
	
	Display(message,color);
}

}
#pragma endregion PrivateFunctions

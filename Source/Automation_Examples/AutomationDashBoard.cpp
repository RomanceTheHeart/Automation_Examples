// Fill out your copyright notice in the Description page of Project Settings.


#include "AutomationDashBoard.h"
#include "EditorLevelLibrary.h"

void UAutomationDashBoard::OrganizeWorldOutliner()
{
	TArray<AActor*> AllActors = UEditorLevelLibrary::GetAllLevelActors();
	for (AActor* actors : AllActors)
	{
		if (ensure(actors))
		{
		 const FName* FolderName = FolderMap.Find(actors->GetClass());
		 if (ensure(FolderName))
		 {
			 actors->SetFolderPath(*FolderName); 
		 }
		}
	}


}


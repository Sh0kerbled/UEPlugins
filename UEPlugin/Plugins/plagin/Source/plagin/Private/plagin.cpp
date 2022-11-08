// Copyright Epic Games, Inc. All Rights Reserved.

#include "plagin.h"
#include "plaginStyle.h"
#include "plaginCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName plaginTabName("plagin");

#define LOCTEXT_NAMESPACE "FplaginModule"

void FplaginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FplaginStyle::Initialize();
	FplaginStyle::ReloadTextures();

	FplaginCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FplaginCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FplaginModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FplaginModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(plaginTabName, FOnSpawnTab::CreateRaw(this, &FplaginModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FplaginTabTitle", "plagin"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(plaginTabName,
	FOnSpawnTab::CreateRaw(this, &FplaginModule::OnSpawnPluginTab))
	.SetDisplayName(LOCTEXT("FStandaloneWindowTestTabTitle",
	"StandaloneWindowTest"))
	.SetMenuType(ETabSpawnerMenuType::Hidden);

}

void FplaginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FplaginStyle::Shutdown();

	FplaginCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(plaginTabName);
}

TSharedRef<SDockTab> FplaginModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FplaginModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("plagin.cpp"))
		);

	return SNew(SDockTab)
.TabRole(ETabRole::NomadTab)
[
SNew(SBox)
.HAlign(HAlign_Center)
.VAlign(VAlign_Center)
[
SNew(SButton)
.OnClicked_Lambda([]()
{
	if (GEditor)
	{
		for (FSelectionIterator
		Iter((GEditor->GetSelectedActorIterator())); Iter; ++Iter)
		{
		AActor* Actor = Cast<AActor>(*Iter);
			if (Actor)
			{
			Actor->AddActorLocalOffset(FVector(50.f));
			}
			}
	}
		return FReply::Handled();
})
	[
	SNew(STextBlock)
	.Text(WidgetText)
	]
	]
	];
}

void FplaginModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(plaginTabName);
}

void FplaginModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FplaginCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FplaginCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FplaginModule, plagin)
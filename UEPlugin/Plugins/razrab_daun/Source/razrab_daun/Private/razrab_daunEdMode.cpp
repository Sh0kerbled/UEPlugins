// Copyright Epic Games, Inc. All Rights Reserved.

#include "razrab_daunEdMode.h"
#include "razrab_daunEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"
#include "Engine/Selection.h"

const FEditorModeID Frazrab_daunEdMode::EM_razrab_daunEdModeId = TEXT("EM_razrab_daunEdMode");

Frazrab_daunEdMode::Frazrab_daunEdMode()
{

}

Frazrab_daunEdMode::~Frazrab_daunEdMode()
{

}

void Frazrab_daunEdMode::ActorSelectionChangeNotify()
{
	FEdMode::ActorSelectionChangeNotify();
	UpdateSelectedActors();
}

void Frazrab_daunEdMode::UpdateSelectedActors()
{
	SelectedActors.Empty();
	USelection* ActorsSelection = GEditor->GetSelectedActors();
	for (FSelectionIterator Iter(*ActorsSelection); Iter; ++Iter)
	{
		AActor* LevelActor = Cast<AActor>(*Iter);
		if (LevelActor && !SelectedActors.Contains(LevelActor))
		{
			SelectedActors.Add(LevelActor);
		}
	}
}

void Frazrab_daunEdMode::Render(const FSceneView* View, FViewport* Viewport,
FPrimitiveDrawInterface* PDI)
{
	for (AActor* BoundedActor : SelectedActors)
	{
		DrawWireBox(
		PDI,
		BoundedActor->GetComponentsBoundingBox(true),
		FColor::Yellow,
		1);
	}
	FEdMode::Render(View, Viewport, PDI);
}

void Frazrab_daunEdMode::DrawHUD(FEditorViewportClient* ViewportClient,
FViewport* Viewport, const FSceneView* View, FCanvas* Canvas)
{
	FEdMode::DrawHUD(ViewportClient, Viewport, View, Canvas);
	for (AActor* SelectedActor : SelectedActors)
	{
		if (Canvas)
		{
			FBox Bounds = SelectedActor->GetComponentsBoundingBox(true);
			
			FVector drawPos = Bounds.GetCenter() + FVector(0.f, 0.f, Bounds.GetExtent().Z);
			
			FVector2D PixelLocation;
			View->ScreenToPixel(View->WorldToScreen(drawPos), PixelLocation);
			
			PixelLocation /= ViewportClient->GetDPIScale();
			
			UFont* RenderFont = GEngine->GetSmallFont();
			
			Canvas->DrawShadowedText(PixelLocation.X, PixelLocation.Y, FText::FromString(SelectedActor->GetName()), RenderFont, FColor::Yellow);
			
		}
	}
}

void Frazrab_daunEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new Frazrab_daunEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void Frazrab_daunEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool Frazrab_daunEdMode::UsesToolkits() const
{
	return true;
}





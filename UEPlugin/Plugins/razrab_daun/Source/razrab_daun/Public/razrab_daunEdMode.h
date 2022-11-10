// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"

class Frazrab_daunEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_razrab_daunEdModeId;
public:
	Frazrab_daunEdMode();
	virtual ~Frazrab_daunEdMode();

	// FEdMode interface
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas) override;
	virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	virtual void ActorSelectionChangeNotify() override;
	bool UsesToolkits() const override;
	// End of FEdMode interface

	protected:
	
    TArray<AActor*> SelectedActors;
	
    void UpdateSelectedActors();
	
};

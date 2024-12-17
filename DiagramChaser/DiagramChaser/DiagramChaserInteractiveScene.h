#pragma once

#include "DiagramChaserScene.h"
#include "Node.h"

class DiagramChaserInteractiveScene  : public DiagramChaserScene
{
public:
	DiagramChaserInteractiveScene(QWidget *parent=nullptr);
	~DiagramChaserInteractiveScene();

	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
};

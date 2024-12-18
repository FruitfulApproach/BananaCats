#include "stdafx.h"
#include "DiagramChaserInteractiveScene.h"

DiagramChaserInteractiveScene::DiagramChaserInteractiveScene(QWidget *parent)
	: DiagramChaserScene(parent)
{}

DiagramChaserInteractiveScene::~DiagramChaserInteractiveScene()
{}

void DiagramChaserInteractiveScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
	auto itemAtMouse = itemAt(event->scenePos(), QTransform());

	if (itemAtMouse == nullptr)
	{
		auto node = new Node();
		node->setFlags(node->flags() | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable |
			QGraphicsItem::ItemIsMovable);
		node->setPos(event->scenePos());
		addItem(node);		
	}
}

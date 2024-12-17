#include "stdafx.h"
#include "Node.h"

Node::Node(QGraphicsItem *parent)
	: QGraphicsObject(parent)
{}

QRectF Node::boundingRect() const
{
	return defaultRect;
}

void Node::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawRoundedRect(boundingRect(), cornerRadius, cornerRadius);
}

Node::~Node()
{}

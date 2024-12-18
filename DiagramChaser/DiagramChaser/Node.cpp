#include "stdafx.h"
#include "Node.h"

Node::Node(QGraphicsItem *parent)
	: QGraphicsObject(parent)
{
	setFlags(ItemSendsGeometryChanges|ItemSendsScenePositionChanges);
}

QRectF Node::boundingRect() const
{
	if (childItems().length())
	{
		return childrenBoundingRect();
	}

	return emptyRect;
}

void Node::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setRenderHint(QPainter::Antialiasing);
	painter->setPen(borderPen);
	painter->setBrush(fillBrush);
	painter->drawRoundedRect(boundingRect(), cornerRadius, cornerRadius);	
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant& value)
{
	if (change == ItemPositionChange && scene()) 
	{
		handleCollisions(value.toPointF()-pos());
	}
	else if (change == ItemPositionHasChanged)
	{
		collisionMemo.clear();
	}
	return QGraphicsItem::itemChange(change, value);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	handleCollisions(event->pos()-event->lastPos());
	QGraphicsObject::mouseMoveEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	collisionMemo.clear();
	QGraphicsObject::mouseReleaseEvent(event);
}

void Node::handleCollisions(const QPointF& deltaPos)
{
	auto itemsColliding = collidingItems();

	if (itemsColliding.length())
	{
		collisionMemo.insert(this);

		for (auto item : itemsColliding)
		{
			auto nodeItem = dynamic_cast<Node*>(item);

			if (nodeItem != nullptr)
			{
				if (QPointF::dotProduct(nodeItem->pos() - pos(), deltaPos) > 0)
				{
					if (!collisionMemo.contains(nodeItem))
					{
						collisionMemo.insert(nodeItem);
						nodeItem->setPos(nodeItem->pos() + deltaPos);
					}
				}
			}
		}
	}
}

Node::~Node()
{}

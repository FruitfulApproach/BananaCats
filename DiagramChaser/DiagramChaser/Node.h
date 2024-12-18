#pragma once

#include <QGraphicsObject>

class Node  : public QGraphicsObject
{
	Q_OBJECT

public:
	Node(QGraphicsItem *parent=nullptr);
	virtual ~Node();
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
	void handleCollisions(const QPointF& newPos);

private:
	// Styling:
	QPen borderPen = QPen(QColor(51, 51, 255), 2);
	QBrush fillBrush = QBrush(QColor(255, 255, 102));
	QRectF emptyRect = QRectF(-15, -15, 30, 30);
	double cornerRadius = 15;

	// Collision handling:
	bool beingPushed = false;
	QSet<Node*> collisionMemo;
};

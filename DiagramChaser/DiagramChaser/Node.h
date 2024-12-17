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

private:
	// Styling:


	// Constants:
	const QRectF defaultRect = QRectF(-50, -50, 100, 100);
	const float defaultCornerRadius = 15;
};

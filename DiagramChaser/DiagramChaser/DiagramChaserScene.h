#pragma once

#include <QGraphicsScene>

class DiagramChaserScene  : public QGraphicsScene
{
	Q_OBJECT

public:
	DiagramChaserScene(QWidget *parent=nullptr);
	~DiagramChaserScene();

};

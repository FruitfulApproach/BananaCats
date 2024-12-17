#pragma once

#include "stdafx.h"
#include <QGraphicsView>

class DiagramChaserView  : public QGraphicsView
{
	Q_OBJECT

public:
	DiagramChaserView(QWidget *parent=nullptr);
	~DiagramChaserView();

};

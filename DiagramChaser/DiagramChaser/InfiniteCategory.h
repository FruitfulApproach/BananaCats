#pragma once

#include <QWidget>
#include "ui_InfiniteCategory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InfiniteCategoryClass; };
QT_END_NAMESPACE

class InfiniteCategory : public QWidget
{
	Q_OBJECT

public:
	InfiniteCategory(QWidget *parent = nullptr);
	~InfiniteCategory();

private:
	Ui::InfiniteCategoryClass *ui;
};

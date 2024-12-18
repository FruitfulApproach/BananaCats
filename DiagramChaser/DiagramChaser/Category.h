#pragma once

#include <QDialog>
#include "ui_Category.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CategoryClass; };
QT_END_NAMESPACE

class Category : public QDialog
{
	Q_OBJECT

public:
	Category(QWidget *parent = nullptr);
	~Category();

public:
	Ui::CategoryClass *ui;
};

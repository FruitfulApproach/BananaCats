#include "stdafx.h"
#include "InfiniteCategory.h"

InfiniteCategory::InfiniteCategory(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::InfiniteCategoryClass())
{
	ui->setupUi(this);
}

InfiniteCategory::~InfiniteCategory()
{
	delete ui;
}

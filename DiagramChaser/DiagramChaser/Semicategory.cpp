#include "stdafx.h"
#include "Semicategory.h"

Semicategory::Semicategory(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CategoryClass())
{
	ui->setupUi(this);
}

Semicategory::~Semicategory()
{
	delete ui;
}

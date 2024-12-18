#include "stdafx.h"
#include "Category.h"

Category::Category(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::CategoryClass())
{
	ui->setupUi(this);
	connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Category::accept);
	connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Category::reject);
}

Category::~Category()
{
	delete ui;
}

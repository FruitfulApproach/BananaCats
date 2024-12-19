#pragma once

#include "stdafx.h"
#include <QApplication>
#include "CategoryDialog.h"


class DiagramChaserApp  : public QApplication
{
public:
	DiagramChaserApp(int& argc, char** argv);
	~DiagramChaserApp();

	void addCategory(CategoryDialog* category)
	{
		categories[category->ui->categoryName->text()] = category;
	}

	bool containsCategoryNamed(const QString& categoryName)
	{
		return categories.contains(categoryName);
	}
	
	void removeCategory(CategoryDialog* category)
	{
		categories.remove(category->ui->categoryName->text());
	}

	CategoryDialog*  category(const QString& categoryName)
	{
		return categories[categoryName];
	}
	
	QList<CategoryDialog*> listCategoriesAlphabetically() 
	{
		auto categoryList = categories.values();

		std::sort(categoryList.begin(), categoryList.end(),
			[](CategoryDialog*& A, CategoryDialog*& B) {
				return A->ui->categoryName->text() < B->ui->categoryName->text();
			});
		
		return categoryList;
	}


private:
	QMap<QString, CategoryDialog*> categories;
};

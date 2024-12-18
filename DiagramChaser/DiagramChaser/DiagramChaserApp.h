#pragma once

#include "stdafx.h"
#include <QApplication>


class DiagramChaserApp  : public QApplication
{
public:
	DiagramChaserApp(int& argc, char** argv);
	~DiagramChaserApp();

	void addCategory(Category* category)
	{
		categories[category->ui->categoryName->text()] = category;
	}

	bool containsCategoryNamed(const QString& categoryName)
	{
		return categories.contains(categoryName);
	}
	
	void removeCategory(Category* category)
	{
		categories.remove(category->ui->categoryName->text());
	}

	Category*  category(const QString& categoryName)
	{
		return categories[categoryName];
	}
	
	QList<Category*> listCategoriesAlphabetically() 
	{
		auto categoryList = categories.values();

		std::sort(categoryList.begin(), categoryList.end(),
			[](const Category*& A, const Category*& B) {
				return A->ui->categoryName->text() < B->ui->categoryName->text();
			});
		
		return categoryList;
	}


private:
	QMap<QString, Category*> categories;
};

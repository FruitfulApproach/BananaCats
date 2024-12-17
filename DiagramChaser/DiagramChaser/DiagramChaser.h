#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DiagramChaser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DiagramChaserClass; };
QT_END_NAMESPACE

class DiagramChaser : public QMainWindow
{
    Q_OBJECT

public:
    DiagramChaser(QWidget *parent = nullptr);
    ~DiagramChaser();

private:
    Ui::DiagramChaserClass *ui;
};

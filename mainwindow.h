#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QIcon>

#include "imgdiagramwidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    ImgDiagramWidget IDW;

    void CreateLayout();

};

#endif // MAINWINDOW_H

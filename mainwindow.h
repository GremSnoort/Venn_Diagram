#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QIcon>
#include <QtSql/QSqlTableModel>
#include <QModelIndex>

#include "imgdiagramwidget.h"
#include "usersession_exprtoimgwidget.h"
#include "database.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    ImgDiagramWidget IDW;
    UserSession_ExprToImgWidget US_ETIW;

    void CreateLayout();

    DataBase        *db;
    QSqlTableModel  *model;
};

#endif // MAINWINDOW_H

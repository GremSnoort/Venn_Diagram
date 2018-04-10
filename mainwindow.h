#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QIcon>
#include <QScopedPointer>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QDockWidget>

#include "usersession.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QScopedPointer<UserSession> user_session;

    void CreateDocks();

    void CreateMenus();

    void CreateConnections();

    void CreateActions();

    QScopedPointer<QAction> start_usersession;
};

#endif // MAINWINDOW_H

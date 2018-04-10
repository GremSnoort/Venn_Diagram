#ifndef USERSESSION_H
#define USERSESSION_H

#include <QObject>
#include <QWidget>
#include <QScopedPointer>
#include <QtSql/QSqlTableModel>
#include <QModelIndex>
#include <QVBoxLayout>
#include <QList>

#include "imgdiagramwidget.h"
#include "usersession_exprtoimgwidget.h"
#include "database.h"

class UserSession : public QWidget
{
    Q_OBJECT
public:
    explicit UserSession(QWidget *parent = nullptr);

private:

    void CreateLayout();

    void GenerateTasks();

    QScopedPointer<ImgDiagramWidget> img_diagram_widget;
    QScopedPointer<UserSession_ExprToImgWidget> user_session_expr_to_img_widget;

    QScopedPointer<QList<data_ExprToImg>> tasks;

    DataBase db;
    QScopedPointer<QSqlTableModel> model;



signals:

public slots:

    void StartNewSession();
};

#endif // USERSESSION_H

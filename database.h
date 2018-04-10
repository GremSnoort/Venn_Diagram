#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QWidget>
#include <QCoreApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <string>

#include "datatypes.h"

#define DATABASE_HOSTNAME   "DESKTOP-92FT46K"
#define DATABASE_NAME       "C:/Users/Eva/Documents/Qt2018/Venn_Diagram/VennTasks.db"

#define TABLE               "ExprToImage"
#define TABLE_ID            "id"
#define TABLE_EXPR          "expr"
#define TABLE_KEY           "key"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    bool openDataBase();        // Открытие базы данных

public:

    QSqlDatabase db;

    data_ExprToImg GetNewRand_ExprToImg();

    void closeDataBase();

    QString GetRand();

private:



public slots:

};

#endif // DATABASE_H

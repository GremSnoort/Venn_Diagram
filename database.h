#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QWidget>
#include <QCoreApplication>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

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

private:

    void closeDataBase();

public slots:

};

#endif // DATABASE_H

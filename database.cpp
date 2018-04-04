#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

int DataBase::GetRand(int size)
{
    return rand() % 2;
}

QStringList DataBase::GetNewRand_ExprToImg()
{
    QStringList List;

    QSqlQuery query = QSqlQuery(db);
    bool ok = query.exec("SELECT COUNT(1) FROM `" TABLE "`;");
    ok = query.exec("select `Expr`, `Key` from `" TABLE "` where `ID` = " + QString(GetRand(0)) + ";");
    qDebug()<<query.lastError().text();

    while (query.next())
    {
        QString expr = query.value(0).toString();
        QString key = query.value(1).toString();

        List<<expr<<key;
    }

    return List;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if (!db.open())
    {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

        return false;
    }
    else
        return true;
}

void DataBase::closeDataBase()
{
    db.close();
}

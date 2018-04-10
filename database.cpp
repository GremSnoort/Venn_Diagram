#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    bool ok = openDataBase();
    qDebug()<<"database OPENED: "<<ok<<endl;
}

DataBase::~DataBase()
{

}

QString DataBase::GetRand()
{
    QString str = QString::number(rand() % 2);

    return str;
}

data_ExprToImg DataBase::GetNewRand_ExprToImg()
{
    data_ExprToImg List;

    QSqlQuery query = QSqlQuery(db);
    bool ok = query.exec("SELECT COUNT(1) FROM `ExprToImage`;");
    ok = query.exec("select Expr, Key from ExprToImage where ID = " + GetRand() + ";");
    qDebug()<<query.lastError().text();

    while (query.next())
    {
        QString expr = query.value(0).toString();
        QString key = query.value(1).toString();

        List.expr = expr;
        List.key = key;
        qDebug()<<List.expr<<"  "<<List.key<<endl;
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

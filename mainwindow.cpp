#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/pic/icon.png"));
    CreateLayout();

    db = new DataBase();
    bool ok = db->openDataBase();

    model = new QSqlTableModel(0, db->db);
    model->setTable(TABLE);
    model->select();

    QTextStream out(stdout);
    out << model->lastError().driverText()<<endl;

    bool y = true;

    QSqlQuery query = QSqlQuery(db->db);
    bool g = query.exec("select * from `" TABLE "`;");
    out<<query.lastError().text();
    bool k = false;

    while (query.next())
    {
    QString _id = query.value(0).toString();
    QString name = query.value(1).toString();
    QTextStream out(stdout);
    out<<_id<<"  )00000   "<< name<<endl;
    qDebug()<<_id<<" 677676777 "<<name;
    }

    /*QSqlTableModel m_model;
    m_model.setTable("test");

    out << m_model.lastError().driverText()<<endl;

    //Осуществляем запрос


    //Выводим значения из запроса
    */
}

MainWindow::~MainWindow()
{

}

void MainWindow::CreateLayout()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(&IDW);

    layout->addWidget(spacer);

    setLayout(layout);
}

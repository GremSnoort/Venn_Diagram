#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/pic/icon.png"));
    CreateLayout();

    db = new DataBase();
    bool ok = db->openDataBase();

    /*model = new QSqlTableModel(0, db->db);
    model->setTable(TABLE);
    model->select();

    QTextStream out(stdout);
    out << model->lastError().driverText()<<endl;*/



}

MainWindow::~MainWindow()
{

}

void MainWindow::CreateLayout()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(&US_ETIW);
    layout->addWidget(&IDW);

    layout->addWidget(spacer);

    setLayout(layout);
}

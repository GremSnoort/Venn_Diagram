#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{    
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/pic/icon.png"));
    CreateLayout();
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

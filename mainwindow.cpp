#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    , user_session(new UserSession(this))
{
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/pic/icon.png"));

    CreateActions();
    CreateMenus();
    CreateConnections();
    CreateDocks();

    //CreateLayout();

    /*model = new QSqlTableModel(0, db->db);
    model->setTable(TABLE);
    model->select();

    QTextStream out(stdout);
    out << model->lastError().driverText()<<endl;*/
}

MainWindow::~MainWindow()
{

}

void MainWindow::CreateDocks()
{
    QMenu* view = menuBar()->addMenu(tr("&View"));

    QDockWidget* userDock = new QDockWidget(tr("User Session"), this);
    userDock->setObjectName("UserSessionDock");
    userDock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable);
    userDock->setWidget(user_session.data());
    addDockWidget(Qt::LeftDockWidgetArea, userDock);
    view->addAction(userDock->toggleViewAction());
    userDock->close();
}

void MainWindow::CreateMenus()
{
    QMenu* session = menuBar()->addMenu(tr("Session"));
    session->addAction(start_usersession.data());
}

void MainWindow::CreateActions()
{
    start_usersession.reset(new QAction(tr("New user session"), this));
}

void MainWindow::CreateConnections()
{
    QObject::connect(start_usersession.data(), &QAction::triggered, user_session.data(), &UserSession::StartNewSession);
}

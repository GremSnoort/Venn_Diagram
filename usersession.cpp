#include "usersession.h"

UserSession::UserSession(QWidget *parent)
    : QWidget(parent)

    , img_diagram_widget(new ImgDiagramWidget(this))
    , user_session_expr_to_img_widget(new UserSession_ExprToImgWidget(this))
    , tasks(new QList<data_ExprToImg>())
    , model(new QSqlTableModel())    
{
    CreateLayout();
}

void UserSession::CreateLayout()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(user_session_expr_to_img_widget.data());
    layout->addWidget(img_diagram_widget.data());

    layout->addWidget(spacer);

    setLayout(layout);
}

void UserSession::GenerateTasks()
{
    tasks->clear();
    for(int i=0; i<20; i++)
    {
        tasks->append(db.GetNewRand_ExprToImg());
        //qDebug()<<tasks->last().key<<endl;
    }
}

void UserSession::StartNewSession()
{
    GenerateTasks();

    user_session_expr_to_img_widget->SetExpr(tasks->at(0).expr);
}

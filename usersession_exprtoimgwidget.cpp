#include "usersession_exprtoimgwidget.h"

UserSession_ExprToImgWidget::UserSession_ExprToImgWidget(QWidget *parent)
    : QWidget(parent)
    , ExprLabel(new QLabel("", this))
    , PrevButton(new QPushButton("Previous", this))
    , NextButton(new QPushButton("Next", this))
    , CheckAnswerButton(new QPushButton("Check Answer", this))
{
    setFixedSize(400, 100);
    CreateLayout();
}

void UserSession_ExprToImgWidget::CreateLayout()
{
    QGridLayout* layout = new QGridLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ExprLabel.data()->setStyleSheet(LABEL_STYLE);
    PrevButton.data()->setStyleSheet(BUTTON_STYLE);
    CheckAnswerButton.data()->setStyleSheet(BUTTON_STYLE);
    NextButton.data()->setStyleSheet(BUTTON_STYLE);

    ExprLabel.data()->setMaximumHeight(25);
    ExprLabel.data()->setAlignment(Qt::AlignCenter);

    layout->addWidget(ExprLabel.data(), 0, 0, 0, 3, Qt::AlignTop);

    layout->addWidget(PrevButton.data(), 1, 0, Qt::AlignBottom);
    layout->addWidget(CheckAnswerButton.data(), 1, 1, Qt::AlignBottom);
    layout->addWidget(NextButton.data(), 1, 2, Qt::AlignBottom);

    layout->setRowMinimumHeight(0, 35);
    layout->setColumnMinimumWidth(0, 133);
    layout->setColumnMinimumWidth(1, 133);
    layout->setColumnMinimumWidth(2, 133);

    layout->addWidget(spacer);

    setLayout(layout);
}

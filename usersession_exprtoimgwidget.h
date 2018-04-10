#ifndef USERSESSION_EXPRTOIMGWIDGET_H
#define USERSESSION_EXPRTOIMGWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QScopedPointer>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

#define BUTTON_STYLE "font: 75 12pt 'Misc Fixed';"
#define LABEL_STYLE  "font: 75 18pt 'Misc Fixed';"

class UserSession_ExprToImgWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UserSession_ExprToImgWidget(QWidget *parent = nullptr);

    void SetExpr(QString expr);

    QScopedPointer<QPushButton> PrevButton;
    QScopedPointer<QPushButton> CheckAnswerButton;
    QScopedPointer<QPushButton> NextButton;    

private:

    void CreateLayout();

    QScopedPointer<QLabel> ExprLabel;    

signals:

public slots:
};

#endif // USERSESSION_EXPRTOIMGWIDGET_H

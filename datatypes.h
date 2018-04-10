#ifndef DATATYPES_H
#define DATATYPES_H

#include <QString>
#include <QObject>

struct data_ExprToImg
{
    QString expr;
    QString key;

    data_ExprToImg()
    {
        expr = "";
        key = "";
    }
};

Q_DECLARE_METATYPE(data_ExprToImg)

#endif // DATATYPES_H

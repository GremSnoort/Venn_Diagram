#ifndef IMGDIAGRAMWIDGET_H
#define IMGDIAGRAMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QScopedPointer>
#include <QVBoxLayout>
#include <QVector>
#include <QPointF>
#include <QPolygon>
#include <QVector>
#include <QPainter>
#include <QMouseEvent>
#include <QTextItem>

class ImgDiagramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImgDiagramWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void GeneratePolygons();

    void paintZone(int i);

    QVector<bool> zones = QVector<bool>{0, 0, 0, 0, 0, 0, 0};//заливка
    QVector<QPolygon> poly_zones = QVector<QPolygon>(7);//собственно зоны

    int R = 99;

    int x01 = 132;
    int x02 = 198;
    int x03 = 264;

    int y01 = 231;
    int y02 = 132;
    int y03 = 231;

    bool checkA(int x, int y)
    {
        return (x-x01)*(x-x01)+(y-y01)*(y-y01) < R*R;
    }

    bool checkB(int x, int y)
    {
        return (x-x02)*(x-x02)+(y-y02)*(y-y02) < R*R;
    }

    bool checkC(int x, int y)
    {
        return (x-x03)*(x-x03)+(y-y03)*(y-y03) < R*R;
    }

signals:

public slots:    
};

#endif // IMGDIAGRAMWIDGET_H

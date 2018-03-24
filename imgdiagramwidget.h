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

    QVector<bool> zones = QVector<bool>{0, 0, 0, 0, 0, 0, 0};
    QVector<QPolygon> poly_zones = QVector<QPolygon>(7);

    int R = 100;

    int x01 = 150;
    int x02 = 200;
    int x03 = 250;

    int y01 = 250;
    int y02 = 150;
    int y03 = 250;

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

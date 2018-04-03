#include "imgdiagramwidget.h"

ImgDiagramWidget::ImgDiagramWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(400, 400);
    GeneratePolygons();
}

void ImgDiagramWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    for(int i=0; i<7; i++)
    {
        if(zones[i])
            paintZone(i);
    }

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.drawEllipse(QPoint(x01, y01), R, R);
    painter.drawEllipse(QPoint(x02, y02), R, R);
    painter.drawEllipse(QPoint(x03, y03), R, R);    
    painter.drawText(QPoint(x01-R, y01+R), "B");
    painter.drawText(QPoint(x02, y02-R-10), "A");
    painter.drawText(QPoint(x03+R, y03+R), "C");
}

void ImgDiagramWidget::GeneratePolygons()
{
    for(int x=33; x<363; x++)
    {
        for(int y=33; y<363; y++)
        {
            bool A = checkA(x, y);
            bool B = checkB(x, y);
            bool C = checkC(x, y);

            if(A && !B && !C)
                poly_zones[0] << QPoint(x, y);

            else if(!A && B && !C)
                poly_zones[1] << QPoint(x, y);

            else if(!A && !B && C)
                poly_zones[2] << QPoint(x, y);

            else if(A && B && !C)
                poly_zones[3] << QPoint(x, y);

            else if(A && !B && C)
                poly_zones[4] << QPoint(x, y);

            else if(!A && B && C)
                poly_zones[5] << QPoint(x, y);

            else if(A && B && C)
                poly_zones[6] << QPoint(x, y);
        }
    }
}

void ImgDiagramWidget::paintZone(int i)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));

    QPainterPath path;
    path.addPolygon(poly_zones[i]);

    QBrush brush = QBrush(QColor(Qt::green));
    painter.setBrush(brush);

    painter.drawPolygon(poly_zones[i]);  //  контур фигуры
    painter.fillPath(path,brush);  //  заливка
}

void ImgDiagramWidget::mousePressEvent(QMouseEvent *event)
{
    bool A = checkA(event->pos().x(), event->pos().y());
    bool B = checkB(event->pos().x(), event->pos().y());
    bool C = checkC(event->pos().x(), event->pos().y());

    if(A && !B && !C)      //A
        zones[0] = !zones[0];

    else if(!A && B && !C) //B
        zones[1] = !zones[1];

    else if(!A && !B && C) //C
        zones[2] = !zones[2];

    else if(A && B && !C)  //AB
        zones[3] = !zones[3];

    else if(A && !B && C)  //AC
        zones[4] = !zones[4];

    else if(!A && B && C)  //BC
        zones[5] = !zones[5];

    else if(A && B && C)   //ABC
        zones[6] = !zones[6];

    else
        return;

    repaint();
}

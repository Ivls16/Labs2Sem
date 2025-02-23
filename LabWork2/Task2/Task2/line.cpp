#include "line.h"

Line::Line(QPointF first, QPointF second, MyGraphicsView* gv): Polygon(first, second, gv)
{

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen(Qt::black, 3);

    painter->setPen(pen);

    painter->drawLine(first, second);
}

double Line::area() {
    return 0;
}

double Line::perimeter() {
    return QLineF(first, second).length();
}


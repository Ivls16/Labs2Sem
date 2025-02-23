#include "rhombus.h"

Rhombus::Rhombus(QPointF first, QPointF second, MyGraphicsView* gv): Polygon(first, second, gv)
{

}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPointF points[4] = {
        QPointF(first.x(), (first.y() + second.y()) / 2),
        QPointF((first.x() + second.x()) / 2, first.y()),
        QPointF(second.x(), (first.y() + second.y()) / 2),
        QPointF((first.x() + second.x()) / 2, second.y())
    };

    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawPolygon(points, 4);
}

double Rhombus::area() {
    return abs(first.x() - second.x()) * abs(first.y() - second.y()) / 2;
}

double Rhombus::perimeter() {
    double d1 = abs(first.x() - second.x());
    double d2 = abs(first.y() - second.y());
    return 2 * sqrt(d1 * d1 + d2 * d2);
}


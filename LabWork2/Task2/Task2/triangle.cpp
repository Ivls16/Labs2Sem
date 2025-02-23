#include "triangle.h"

Triangle::Triangle(QPointF first, QPointF second, MyGraphicsView* gv): Polygon(first, second, gv)
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPointF points[3] = {
        QPointF((first.x() + second.x()) / 2, first.y()),
        QPointF(first.x(), second.y()),
        QPointF(second.x(), second.y())
    };

    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawPolygon(points, 3);
}

double Triangle::area() {
    QPointF points[3] = {
        QPointF((first.x() + second.x()) / 2, first.y()),
        QPointF(first.x(), second.y()),
        QPointF(second.x(), second.y())
    };
    return QLineF(points[1], points[2]).length() * abs(first.y() - second.y()) / 2;
}

double Triangle::perimeter() {
    QPointF points[3] = {
        QPointF((first.x() + second.x()) / 2, first.y()),
        QPointF(first.x(), second.y()),
        QPointF(second.x(), second.y())
    };
    return QLineF(points[0], points[1]).length() + QLineF(points[1], points[2]).length() + QLineF(points[0], points[2]).length();
}

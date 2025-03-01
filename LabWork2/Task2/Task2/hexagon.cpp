#include "hexagon.h"

Hexagon::Hexagon(QPointF first, QPointF second, MyGraphicsView* gv): Polygon(first, second, gv)
{

}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawEllipse(boundingRect().center() + getMassCenterOffset(), 3, 3);

    QPointF points[6] = {
        QPointF((first.x() + second.x()) / 2, std::min(first.y(), second.y())),
        QPointF(std::min(first.x(), second.x()), std::min(first.y(), second.y()) + abs(first.y() - second.y()) / 3.0),
        QPointF(std::min(first.x(), second.x()), std::min(first.y(), second.y()) + abs(first.y() - second.y()) / 3.0 * 2.0),
        QPointF((first.x() + second.x()) / 2, std::max(first.y(), second.y())),
        QPointF(std::max(first.x(), second.x()), std::min(first.y(), second.y()) + abs(first.y() - second.y()) / 3.0 * 2.0),
        QPointF(std::max(first.x(), second.x()), std::min(first.y(), second.y()) + abs(first.y() - second.y()) / 3.0)
    };

    painter->drawPolygon(points, 6);
}

double Hexagon::area() {
    return 0;
}

double Hexagon::perimeter() {
    return 0;
}


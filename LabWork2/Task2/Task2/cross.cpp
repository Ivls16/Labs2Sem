#include "cross.h"

Cross::Cross(QPointF first, QPointF second, MyGraphicsView* gv): Polygon(first, second, gv)
{

}

void Cross::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen(Qt::black, 3);
    painter->setPen(pen);

    int x1 = first.x(), y1 = first.y(), x2 = second.x(), y2 = second.y();
    if (x1 > x2) {
        std::swap(x1, x2);
    }
    if (y1 > y2) {
        std::swap(y1, y2);
    }
    QPointF points[12] = {
        QPointF(x1 + 1.0 / 3.0 * (x2 - x1), y1),
        QPointF(x1 + 2.0 / 3.0 * (x2 - x1), y1),
        QPointF(x1 + 2.0 / 3.0 * (x2 - x1), y1 + 1.0 / 3.0 * (y2 - y1)),
        QPointF(x2, y1 + 1.0 / 3.0 * (y2 - y1)),
        QPointF(x2, y1 + 2.0 / 3.0 * (y2 - y1)),
        QPointF(x1 + 2.0 / 3.0 * (x2 - x1), y1 + 2.0 / 3.0 * (y2 - y1)),
        QPointF(x1 + 2.0 / 3.0 * (x2 - x1), y2),
        QPointF(x1 + 1.0 / 3.0 * (x2 - x1), y2),
        QPointF(x1 + 1.0 / 3.0 * (x2 - x1), y1 + 2.0 / 3.0 * (y2 - y1)),
        QPointF(x1, y1 + 2.0 / 3.0 * (y2 - y1)),
        QPointF(x1, y1 + 1.0 / 3.0 * (y2 - y1)),
        QPointF(x1 + 1.0 / 3.0 * (x2 - x1), y1 + 1.0 / 3.0 * (y2 - y1))
    };

    painter->drawEllipse(boundingRect().center() + getMassCenterOffset(), 3, 3);
    painter->drawPolygon(points, 12);
}

double Cross::area() {
    return 5.0 / 9.0 * abs(first.x() - second.x()) * abs(first.y() - second.y());
}

double Cross::perimeter() {
    return (abs(first.x() - second.x()) + abs(first.y() - second.y())) * 2;
}


#include "star.h"

Star::Star(QPointF first, QPointF second, MyGraphicsView* gv, double startAngle, int vertexCount): Polygon(first, second, gv), startAngle(startAngle), vertexCount(vertexCount)
{

}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPointF points[2 * vertexCount];
    double a = abs(first.x() - second.x()) / 2;
    double b = abs(first.y() - second.y()) / 2;
    for (int i = 0; i < 2 * vertexCount; i++) {
        double angle = startAngle * i;
        double mult = (i % 2 == 0 ? 1 : innerScale);
        points[i] = boundingRect().center() - QPointF(a * mult * sin(angle), b * mult * cos(angle));
    }

    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawEllipse(boundingRect().center() + getMassCenterOffset(), 3, 3);
    painter->drawPolygon(points, 2 * vertexCount);
}

double Star::area() {
    return 0;
}

double Star::perimeter() {
    return 0;
}

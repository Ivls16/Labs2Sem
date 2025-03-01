#include "rectangle.h"

Rectangle::Rectangle(QPointF first, QPointF second, MyGraphicsView* gv): Polygon(first, second, gv)
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawEllipse(boundingRect().center() + getMassCenterOffset(), 3, 3);
    painter->drawRect(std::min(first.x(), second.x()), std::min(first.y(), second.y()), abs(first.x() - second.x()), abs(first.y() - second.y()));
}

double Rectangle::area() {
    return abs(first.x() - second.x()) * abs(first.y() - second.y());
}

double Rectangle::perimeter() {
    return (abs(first.x() - second.x()) + abs(first.y() - second.y())) * 2;
}


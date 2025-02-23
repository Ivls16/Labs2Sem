#include "square.h"

Square::Square(QPointF center, int r, MyGraphicsView* gv): Figure(gv), center(center), r(r)
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawRect(center.x() - (scaleX * r), center.y() - (scaleY * r), scaleX * 2 * r, scaleY * 2 * r);
}

QRectF Square::boundingRect() const
{
    QPointF first = center - QPointF(scaleX * r, scaleY * r);
    QPointF second = center + QPointF(scaleX * r, scaleY * r);
    return QRectF(first - QPointF(getRectOffset(), getRectOffset()), second + QPointF(getRectOffset(), getRectOffset()));
}

void Square::updateFigure(QPointF currentPos) {
    r = (int)QLineF(center, currentPos).length();
    update();
}

void Square::setScaleX(double sc) {
    if (sc > 1) {
        scaleX *= 1.01;
        scaleY *= 1.01;
    }
    if (sc < 1) {
        scaleX *= 0.99;
        scaleY *= 0.99;
    }
    update();
}

void Square::setScaleY(double sc) {
    if (sc > 1) {
        scaleX *= 1.01;
        scaleY *= 1.01;
    }
    if (sc < 1) {
        scaleX *= 0.99;
        scaleY *= 0.99;
    }
    update();
}

double Square::area() {
    return 4 * r * r;
}

double Square::perimeter() {
    return 8 * r;
}

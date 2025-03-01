#include "circle.h"

Circle::Circle(QPointF center, int r, MyGraphicsView* gv): Figure(gv), center(center), r(r)
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen(Qt::black, 3);

    painter->setPen(pen);
    painter->drawEllipse(QPoint(center.x(), center.y()), int(scaleX * r), int(scaleY * r));
    painter->drawEllipse(boundingRect().center() + getMassCenterOffset(), 3, 3);
}

QRectF Circle::boundingRect() const
{
    QPointF first = center - QPointF(scaleX * r, scaleY * r);
    QPointF second = center + QPointF(scaleX * r, scaleY * r);
    return QRectF(first - QPointF(getRectOffset(), getRectOffset()), second + QPointF(getRectOffset(), getRectOffset()));
}

void Circle::updateFigure(QPointF currentPos) {
    r = (int)QLineF(center, currentPos).length();
    update();
}

void Circle::setScaleX(double sc) {
    if (sc > 1) {
        scaleX *= 1.01;
    }
    if (sc < 1) {
        scaleX *= 0.99;
    }
    update();
}

void Circle::setScaleY(double sc) {
    if (sc > 1) {
        scaleY *= 1.01;
    }
    if (sc < 1) {
        scaleY *= 0.99;
    }
    update();
}

double Circle::area() {
    return M_PI * scaleX * r * scaleY * r;
}

double Circle::perimeter() {
    return M_PI * (3 * (scaleX * r + scaleY * r) - sqrt((3 * scaleX * r + scaleY * r) * (scaleX + 3 * scaleY * r)));
}


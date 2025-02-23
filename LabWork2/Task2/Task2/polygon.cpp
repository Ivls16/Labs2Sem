#include "polygon.h"

Polygon::Polygon(QPointF first, QPointF second, MyGraphicsView* gv): Figure(gv), first(first), second(second)
{

}

QRectF Polygon::boundingRect() const
{
    return QRectF(first - QPointF(getRectOffset(), getRectOffset()), second + QPointF(getRectOffset(), getRectOffset()));
}

void Polygon::setScaleX(double sc) {
    if (first.x() > second.x()) {
        std::swap(first, second);
    }
    if (sc > 1) {
        if (first.y() < second.y()) {
            first -= QPointF(4, 0);
            second += QPointF(4, 0);
        }
        else {
            first -= QPointF(4, 0);
            second += QPointF(4, 0);
        }
    }
    if (sc < 1) {
        if (first.y() < second.y()) {
            first += QPointF(4, 0);
            second -= QPointF(4, 0);
        }
        else {
            first += QPointF(4, 0);
            second -= QPointF(4, 0);
        }
    }
    update();
}

void Polygon::setScaleY(double sc) {
    if (first.x() > second.x()) {
        std::swap(first, second);
    }
    if (sc > 1) {
        if (first.y() < second.y()) {
            first -= QPointF(0, 4);
            second += QPointF(0, 4);
        }
        else {
            first -= QPointF(0, -4);
            second += QPointF(0, -4);
        }
    }
    if (sc < 1) {
        if (first.y() < second.y()) {
            first += QPointF(0, 4);
            second -= QPointF(0, 4);
        }
        else {
            first += QPointF(0, -4);
            second -= QPointF(0, -4);
        }
    }
    update();
}

void Polygon::updateFigure(QPointF currentPos) {
    second = currentPos;
    update();
}


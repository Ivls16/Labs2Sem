#ifndef STAR_H
#define STAR_H

#include "polygon.h"

class Star : public Polygon
{
public:
    Star(QPointF, QPointF, MyGraphicsView*, double, int);

    double area() override;
    double perimeter() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    double innerScale = 0.5, startAngle;
    int vertexCount;
};

#endif // STAR_H

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

class Triangle: public Polygon
{
public:
    Triangle(QPointF, QPointF, MyGraphicsView*);

    double area() override;
    double perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // TRIANGLE_H

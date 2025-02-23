#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"

class Rectangle: public Polygon
{
public:
    Rectangle(QPointF, QPointF, MyGraphicsView*);

    double area() override;
    double perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // RECTANGLE_H

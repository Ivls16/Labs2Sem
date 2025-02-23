#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "polygon.h"

class Rhombus: public Polygon
{
public:
    Rhombus(QPointF, QPointF, MyGraphicsView*);

    double area() override;
    double perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // RHOMBUS_H

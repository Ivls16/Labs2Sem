#ifndef CROSS_H
#define CROSS_H

#include "polygon.h"

class Cross: public Polygon
{
public:
    Cross(QPointF, QPointF, MyGraphicsView*);

    double area() override;
    double perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // CROSS_H

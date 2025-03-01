#ifndef HEXAGON_H
#define HEXAGON_H

#include "polygon.h"

class Hexagon: public Polygon
{
public:
    Hexagon(QPointF, QPointF, MyGraphicsView*);

    double area() override;
    double perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // HEXAGON_H

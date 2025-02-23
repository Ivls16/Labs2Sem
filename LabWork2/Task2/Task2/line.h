#ifndef LINE_H
#define LINE_H

#include "polygon.h"

class Line: public Polygon
{
public:
    Line(QPointF, QPointF, MyGraphicsView*);

    double area() override;
    double perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif //LINE_H

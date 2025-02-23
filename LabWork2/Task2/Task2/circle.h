#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle: public Figure
{
public:
    Circle(QPointF, int, MyGraphicsView*);
    void updateFigure(QPointF) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void setScaleX(double) override;
    void setScaleY(double) override;

    double area() override;
    double perimeter() override;

    QRectF boundingRect() const override;
private:
    QPointF center;
    int r;
    double scaleX = 1, scaleY = 1;
};

#endif //CIRCLE_H

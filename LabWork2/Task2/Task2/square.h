#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square: public Figure
{
public:
    Square(QPointF, int, MyGraphicsView*);
    void updateFigure(QPointF) override;

    void setScaleX(double) override;
    void setScaleY(double) override;

    double area() override;
    double perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
private:
    QPointF center;
    int r;
    double scaleX = 1, scaleY = 1;
};

#endif // SQUARE_H

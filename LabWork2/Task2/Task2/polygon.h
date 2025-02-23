#ifndef POLYGON_H
#define POLYGON_H

#include "figure.h"

class Polygon : public Figure
{
public:
    Polygon(QPointF, QPointF, MyGraphicsView*);
    void updateFigure(QPointF) override;

    void setScaleX(double) override;
    void setScaleY(double) override;
protected:
    QRectF boundingRect() const override;
    QPointF first, second;
};

#endif // POLYGON_H

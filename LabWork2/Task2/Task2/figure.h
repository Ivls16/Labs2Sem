#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class MyGraphicsView;

class Figure: public QGraphicsItem
{
public:
    Figure(MyGraphicsView*);
    virtual void updateFigure(QPointF) = 0;

    int getRectOffset() const;
    void setRectOffset(int);

    QPointF getMassCenterOffset() const;

    bool isDragging() const;
    void dragTo(QPointF);
    void startDrag(QPointF);
    void finishDrag();
    void setMassCenterOffset(QPoint);

    virtual void setScaleX(double) = 0;
    virtual void setScaleY(double) = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
private:
    int rectOffset;
    bool dragging = false;
    QPointF lastMousePos;
    MyGraphicsView* parent;
    QPointF massCenterOffset = QPointF(0, 0);
};

#endif //FIGURE_H


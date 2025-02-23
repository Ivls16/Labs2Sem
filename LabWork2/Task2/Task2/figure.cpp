#include "mygraphicsview.h"

Figure::Figure(MyGraphicsView* parent): parent(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
}

int Figure::getRectOffset() const {
    return rectOffset;
}

void Figure::setRectOffset(int value) {
    rectOffset = value;
}

bool Figure::isDragging() {
    return dragging;
}

void Figure::dragTo(QPointF event) {
    QPointF delta = event - lastMousePos;
    setPos(pos() + delta);
    lastMousePos = event;
}

void Figure::finishDrag() {
    dragging = false;
}

void Figure::startDrag(QPointF position) {
    dragging = true;
    lastMousePos = position;
}


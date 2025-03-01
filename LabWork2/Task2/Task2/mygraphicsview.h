#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QActionGroup>
#include <vector>
#include <QToolBar>
#include <QMainWindow>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>

#include "circle.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "rhombus.h"
#include "square.h"
#include "cross.h"
#include "figureinfo.h"
#include "fivestar.h"
#include "sixstar.h"
#include "eightstar.h"
#include "hexagon.h"

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QActionGroup*, QMainWindow*, QWidget*);

    void setCurrentFigure(const QPoint);
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QPoint pressPos, releasePos;
    Figure *currentFigure;
    QActionGroup* actions;
    FigureInfo* figureInfo;
    QSlider *scaleItemX, *scaleItemY, *rotation;
    QToolBar *itemToolBar;
    QLineEdit *centerX, *centerY;
    QLabel *perimeter, *area;
};

#endif //MYGRAPHICSVIEW_H

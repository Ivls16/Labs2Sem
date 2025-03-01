#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QActionGroup* actions, QMainWindow* wnd, QWidget* parent): QGraphicsView(parent), actions(actions)
{
    itemToolBar = wnd->addToolBar("ItemToolbar");
    itemToolBar->setFixedWidth(200);
    wnd->addToolBar(Qt::RightToolBarArea, itemToolBar);

    scaleItemX = new QSlider(Qt::Horizontal); scaleItemX->setRange(0, 1000); scaleItemX->setValue(500);
    itemToolBar->addWidget(scaleItemX);
    scaleItemY = new QSlider(Qt::Horizontal); scaleItemY->setRange(0, 1000); scaleItemY->setValue(500);
    itemToolBar->addWidget(scaleItemY);
    rotation = new QSlider(Qt::Horizontal); rotation->setRange(-360, 360); scaleItemY->setValue(0);
    itemToolBar->addWidget(rotation);

    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    centerX = new QLineEdit();
    centerY = new QLineEdit();
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(centerX);
    layout->addWidget(centerY);
    QWidget *container = new QWidget();
    container->setLayout(layout);
    container->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    itemToolBar->addWidget(container);

    area = new QLabel();
    perimeter = new QLabel();
    QHBoxLayout* lyt = new QHBoxLayout();
    lyt->addWidget(area);
    lyt->addWidget(perimeter);
    QWidget *digits = new QWidget();
    digits->setLayout(lyt);
    digits->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    itemToolBar->addWidget(digits);

    figureInfo = new FigureInfo(scaleItemX, scaleItemY, rotation, centerX, centerY, perimeter, area);
}

void MyGraphicsView::setCurrentFigure(const QPoint clickPos) {
    currentFigure = qgraphicsitem_cast<Figure*>(scene()->itemAt(clickPos, QTransform()));
    if (currentFigure) {
        currentFigure->startDrag(clickPos);
    }
}

void MyGraphicsView::mousePressEvent(QMouseEvent* event) {
    pressPos = event->pos();

    if (actions->checkedAction()->text() == "Прямая") {
        currentFigure = new Line(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Круг") {
        currentFigure = new Circle(pressPos, 0, this);
    }
    if (actions->checkedAction()->text() == "Прямоугольник") {
        currentFigure = new Rectangle(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Треугольник") {
        currentFigure = new Triangle(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Ромб") {
        currentFigure = new Rhombus(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Квадрат") {
        currentFigure = new Square(pressPos, 0, this);
    }
    if (actions->checkedAction()->text() == "Крестик") {
        currentFigure = new Cross(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Пятиконечная звезда") {
        currentFigure = new FiveStar(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Шестиконечная звезда") {
        currentFigure = new SixStar(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Восьмиконечная звезда") {
        currentFigure = new EightStar(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Шестиугольник") {
        currentFigure = new Hexagon(pressPos, pressPos, this);
    }
    if (actions->checkedAction()->text() == "Не фигура") {
        currentFigure = nullptr;
        setCurrentFigure(event->pos());
    }

    if (currentFigure) {
        figureInfo->setupFigure(currentFigure);
    }

    if (currentFigure && !currentFigure->isDragging()) {
        scene()->addItem(currentFigure);
    }
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    if (!currentFigure) {
        return;
    }
    currentFigure->setRectOffset(500);
    if (!currentFigure->isDragging()) {
        currentFigure->updateFigure(event->pos());
    }
    else {
        currentFigure->dragTo(event->pos());
    }
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    releasePos = event->pos();
    if (!currentFigure) {
        return;
    }
    currentFigure->setRectOffset(0);
    if (currentFigure->isDragging()) {
        currentFigure->finishDrag();
    }
    currentFigure = nullptr;
}

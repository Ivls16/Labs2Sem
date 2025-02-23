#include "rectangle.h"

Rectangle::Rectangle(QSlider* slider, QWidget* parent): QWidget(parent), slider(slider), x(parent->width() / 2), y(parent->height() / 2 - 100), width(250), height(150) {
    connect(slider, &QSlider::valueChanged, this, &Rectangle::moveIt);
}

void Rectangle::moveIt() {
    setRectangleX(slider->value() * 8);
}

void Rectangle::setRectangleX(int dx) {
    x = dx;
    update();
}

void Rectangle::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setBrush(Qt::transparent);
    painter.drawRect(x - width / 2, y, width, height);
}

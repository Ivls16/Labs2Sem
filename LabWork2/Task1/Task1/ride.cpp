#include "ride.h"

Ride::Ride(QSlider* slider, QWidget* parent): Rectangle(slider, parent) {}

void Ride::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setBrush(Qt::transparent);
    painter.drawRect(x - width / 2, y, width, height);
    painter.drawEllipse(QPoint(x + width / 3, y + height + height / 4), height / 4, height / 4);
    painter.drawEllipse(QPoint(x - width / 3, y + height + height / 4), height / 4, height / 4);
    double fi = (double)(x % 200) / 200 * acos(-1);
    painter.drawLine(QPoint(x + width / 3 + cos(fi) * height / 4, y + height + height / 4 + sin(fi) * height / 4),
                     QPoint(x + width / 3 - cos(fi) * height / 4, y + height + height / 4 - sin(fi) * height / 4));
    painter.drawLine(QPoint(x - width / 3 + cos(fi) * height / 4, y + height + height / 4 + sin(fi) * height / 4),
                     QPoint(x - width / 3 - cos(fi) * height / 4, y + height + height / 4 - sin(fi) * height / 4));
}

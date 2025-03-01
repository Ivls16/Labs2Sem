#include "figureinfo.h"

FigureInfo::FigureInfo(QSlider* scaleX, QSlider* scaleY, QSlider* rotation, QLineEdit* centerX, QLineEdit* centerY, QLabel* area, QLabel* perimeter): scaleX(scaleX), scaleY(scaleY), rotation(rotation), centerX(centerX), centerY(centerY), area(area), perimeter(perimeter)
{
    connect(scaleX, &QSlider::valueChanged, this, &FigureInfo::onScaleChanged);
    connect(scaleY, &QSlider::valueChanged, this, &FigureInfo::onScaleChanged);
    connect(rotation, &QSlider::valueChanged, this, &FigureInfo::onRotationChanged);
    connect(centerX, &QLineEdit::textEdited, this, &FigureInfo::onCenterChanged);
    connect(centerY, &QLineEdit::textEdited, this, &FigureInfo::onCenterChanged);
}

void FigureInfo::setupFigure(Figure* fg) {
    figure = fg;
    settedUp = false;
    scaleX->setValue(500);
    scaleY->setValue(500);
    lstx = lsty = 500;
    rotation->setValue(figure->rotation());

    centerX->setText(QString::number(figure->getMassCenterOffset().x()));
    centerY->setText(QString::number(figure->getMassCenterOffset().y()));

    area->setText(QString::number(figure->area()));
    perimeter->setText(QString::number(figure->perimeter()));
    settedUp = true;
}

void FigureInfo::onScaleChanged() {
    if (!figure || !settedUp) {
        return;
    }
    figure->setRectOffset(500);
    if (scaleX->value() != lstx) {
        figure->setScaleX((scaleX->value() > lstx) ? 2 : 0);
    }
    if (scaleY->value() != lsty) {
        figure->setScaleY((scaleY->value() > lsty) ? 2 : 0);
    }
    lstx = scaleX->value();
    lsty = scaleY->value();
    figure->update();
    figure->setRectOffset(10);
    area->setText(QString::number(figure->area()));
    perimeter->setText(QString::number(figure->perimeter()));
}

void FigureInfo::onRotationChanged() {
    if (!figure || !settedUp) {
        return;
    }
    figure->setTransformOriginPoint(figure->boundingRect().center() + figure->getMassCenterOffset());
    figure->setRotation(rotation->value());
}

void FigureInfo::onCenterChanged() {
    if (!figure || !settedUp) {
        return;
    }
    QPoint newOffset(centerX->text().toInt(), centerY->text().toInt());
    figure->setMassCenterOffset(newOffset);
}

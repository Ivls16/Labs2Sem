#ifndef FIGUREINFO_H
#define FIGUREINFO_H

#include <QSlider>
#include <QObject>
#include <QLineEdit>
#include <QLabel>

#include "figure.h"

class FigureInfo: public QObject
{
    Q_OBJECT
public:
    FigureInfo(QSlider*, QSlider*, QSlider*, QLineEdit*, QLineEdit*, QLabel*, QLabel*);

    void setupFigure(Figure*);

    int scaleToPercent(double);
    double percentToScale(int);
private:
    Figure* figure = nullptr;
    QSlider* scaleX;
    QSlider* scaleY;
    QSlider* rotation;
    QLineEdit *centerX, *centerY;
    QLabel *area, *perimeter;
    bool settedUp;
    int lstx, lsty;
private slots:
    void onScaleChanged();
    void onRotationChanged();
    void onCenterChanged();
};

#endif // FIGUREINFO_H

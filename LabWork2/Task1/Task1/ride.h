#include "rectangle.h"

class Ride: public Rectangle
{
public:
    Ride(QSlider*, QWidget*);
protected:
    void paintEvent(QPaintEvent*) override;
};

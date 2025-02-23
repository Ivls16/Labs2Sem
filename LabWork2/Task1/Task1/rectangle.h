#include <QWidget>
#include <QPainter>
#include <QSlider>

class Rectangle : public QWidget {
    Q_OBJECT

private:
    QSlider* slider;
protected:
    int x, y, width, height;

public:
    explicit Rectangle(QSlider*, QWidget* = nullptr);

    void setRectangleX(int);

private slots:
    void moveIt();

protected:
    void paintEvent(QPaintEvent*) override;
};

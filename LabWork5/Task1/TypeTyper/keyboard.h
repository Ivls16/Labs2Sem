#ifndef KEYBOARD_H
#define KEYBOARD_H

#pragma once
#include <QtWidgets>
#include "locals.h"

namespace Ui {
    class KeyboardWidget;
}

class Keyboard : public QWidget {
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();
    void keyPressEvent(QKeyEvent *event) override;
    void setKeys(int);
public slots:
    void handleButtonClicked();
private:
    Ui::KeyboardWidget *ui;
    QMap<int, QPushButton*> buttonsMap;
};

#endif // KEYBOARD_H

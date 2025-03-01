QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    cross.cpp \
    eightstar.cpp \
    figure.cpp \
    figureinfo.cpp \
    fivestar.cpp \
    hexagon.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    mygraphicsview.cpp \
    polygon.cpp \
    rectangle.cpp \
    rhombus.cpp \
    sixstar.cpp \
    square.cpp \
    star.cpp \
    triangle.cpp

HEADERS += \
    circle.h \
    cross.h \
    eightstar.h \
    figure.h \
    figureinfo.h \
    fivestar.h \
    hexagon.h \
    line.h \
    mainwindow.h \
    mygraphicsview.h \
    polygon.h \
    rectangle.h \
    rhombus.h \
    sixstar.h \
    square.h \
    star.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

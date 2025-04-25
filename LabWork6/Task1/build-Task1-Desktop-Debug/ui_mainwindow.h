/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_id;
    QLineEdit *idLine;
    QLabel *label_name;
    QLineEdit *nameLine;
    QLabel *label_type;
    QLineEdit *typeLine;
    QLabel *label_passenger;
    QLineEdit *passengerLine;
    QLabel *label_power;
    QLineEdit *powerLine;
    QLabel *label_details;
    QLineEdit *detailsLine;
    QHBoxLayout *buttonLayout;
    QPushButton *explicitCreate;
    QPushButton *separatelyCreate;
    QPushButton *pointerCreate;
    QPushButton *referenceCreate;
    QLabel *shipLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"     QWidget {\n"
"         background-color: #ffe6f9;\n"
"         font-family: \"Comic Sans MS\", \"Segoe UI\", sans-serif;\n"
"         font-size: 12pt;\n"
"         color: #6b006b;\n"
"     }\n"
"     QLabel {\n"
"         font-weight: bold;\n"
"         color: #ff66cc;\n"
"     }\n"
"     QLineEdit {\n"
"         background-color: #fff0fb;\n"
"         border: 2px solid #ff99cc;\n"
"         padding: 6px;\n"
"         border-radius: 8px;\n"
"         color: #cc0066;\n"
"     }\n"
"     QPushButton {\n"
"         background-color: qlineargradient(\n"
"             x1: 0, y1: 0, x2: 1, y2: 0,\n"
"             stop: 0 #ff69b4, stop: 1 #ff1493\n"
"         );\n"
"         color: white;\n"
"         font-weight: bold;\n"
"         padding: 8px 14px;\n"
"         border-radius: 10px;\n"
"         border: 1px solid #e75480;\n"
"     }\n"
"     QPushButton:hover {\n"
"         background-color: #ff85b4;\n"
"     }\n"
"     QPushButton:pressed {\n"
"         background-color: #ff3399;\n"
"     }\n"
"     QSta"
                        "tusBar, QMenuBar {\n"
"         background-color: #ffcce6;\n"
"         color: #800040;\n"
"     }\n"
"    "));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_id = new QLabel(centralwidget);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_id, 0, 0, 1, 1);

        idLine = new QLineEdit(centralwidget);
        idLine->setObjectName(QString::fromUtf8("idLine"));

        gridLayout->addWidget(idLine, 0, 1, 1, 1);

        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_name, 1, 0, 1, 1);

        nameLine = new QLineEdit(centralwidget);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));

        gridLayout->addWidget(nameLine, 1, 1, 1, 1);

        label_type = new QLabel(centralwidget);
        label_type->setObjectName(QString::fromUtf8("label_type"));
        label_type->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_type, 2, 0, 1, 1);

        typeLine = new QLineEdit(centralwidget);
        typeLine->setObjectName(QString::fromUtf8("typeLine"));

        gridLayout->addWidget(typeLine, 2, 1, 1, 1);

        label_passenger = new QLabel(centralwidget);
        label_passenger->setObjectName(QString::fromUtf8("label_passenger"));
        label_passenger->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_passenger, 3, 0, 1, 1);

        passengerLine = new QLineEdit(centralwidget);
        passengerLine->setObjectName(QString::fromUtf8("passengerLine"));

        gridLayout->addWidget(passengerLine, 3, 1, 1, 1);

        label_power = new QLabel(centralwidget);
        label_power->setObjectName(QString::fromUtf8("label_power"));
        label_power->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_power, 4, 0, 1, 1);

        powerLine = new QLineEdit(centralwidget);
        powerLine->setObjectName(QString::fromUtf8("powerLine"));

        gridLayout->addWidget(powerLine, 4, 1, 1, 1);

        label_details = new QLabel(centralwidget);
        label_details->setObjectName(QString::fromUtf8("label_details"));
        label_details->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_details, 5, 0, 1, 1);

        detailsLine = new QLineEdit(centralwidget);
        detailsLine->setObjectName(QString::fromUtf8("detailsLine"));

        gridLayout->addWidget(detailsLine, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        explicitCreate = new QPushButton(centralwidget);
        explicitCreate->setObjectName(QString::fromUtf8("explicitCreate"));

        buttonLayout->addWidget(explicitCreate);

        separatelyCreate = new QPushButton(centralwidget);
        separatelyCreate->setObjectName(QString::fromUtf8("separatelyCreate"));

        buttonLayout->addWidget(separatelyCreate);

        pointerCreate = new QPushButton(centralwidget);
        pointerCreate->setObjectName(QString::fromUtf8("pointerCreate"));

        buttonLayout->addWidget(pointerCreate);

        referenceCreate = new QPushButton(centralwidget);
        referenceCreate->setObjectName(QString::fromUtf8("referenceCreate"));

        buttonLayout->addWidget(referenceCreate);


        verticalLayout->addLayout(buttonLayout);

        shipLabel = new QLabel(centralwidget);
        shipLabel->setObjectName(QString::fromUtf8("shipLabel"));
        shipLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(shipLabel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ship Creator", nullptr));
        label_id->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_passenger->setText(QCoreApplication::translate("MainWindow", "Passenger", nullptr));
        label_power->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        label_details->setText(QCoreApplication::translate("MainWindow", "Details", nullptr));
        explicitCreate->setText(QCoreApplication::translate("MainWindow", "Explicit", nullptr));
        separatelyCreate->setText(QCoreApplication::translate("MainWindow", "Separately", nullptr));
        pointerCreate->setText(QCoreApplication::translate("MainWindow", "Pointer", nullptr));
        referenceCreate->setText(QCoreApplication::translate("MainWindow", "Reference", nullptr));
        shipLabel->setText(QCoreApplication::translate("MainWindow", "No ship created", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

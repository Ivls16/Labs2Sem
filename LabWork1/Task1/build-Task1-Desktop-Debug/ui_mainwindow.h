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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *resetTable;
    QPushButton *addDate;
    QPushButton *pushButton_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *nextDay;
    QLabel *label_8;
    QLabel *label_3;
    QPushButton *duration;
    QPushButton *daysTillYourBirthday;
    QPushButton *weekNumber;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *previousDay;
    QLabel *label_4;
    QPushButton *isLeap;
    QLabel *label_5;
    QLineEdit *date;
    QLabel *label;
    QLabel *warning;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(800, 450);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 450));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 391, 241));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(label_2);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(126);

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        resetTable = new QPushButton(verticalLayoutWidget);
        resetTable->setObjectName(QString::fromUtf8("resetTable"));

        horizontalLayout_2->addWidget(resetTable);

        addDate = new QPushButton(verticalLayoutWidget);
        addDate->setObjectName(QString::fromUtf8("addDate"));

        horizontalLayout_2->addWidget(addDate);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(430, 20, 351, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        nextDay = new QPushButton(gridLayoutWidget);
        nextDay->setObjectName(QString::fromUtf8("nextDay"));

        gridLayout->addWidget(nextDay, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        duration = new QPushButton(gridLayoutWidget);
        duration->setObjectName(QString::fromUtf8("duration"));

        gridLayout->addWidget(duration, 5, 0, 1, 1);

        daysTillYourBirthday = new QPushButton(gridLayoutWidget);
        daysTillYourBirthday->setObjectName(QString::fromUtf8("daysTillYourBirthday"));

        gridLayout->addWidget(daysTillYourBirthday, 4, 0, 1, 1);

        weekNumber = new QPushButton(gridLayoutWidget);
        weekNumber->setObjectName(QString::fromUtf8("weekNumber"));

        gridLayout->addWidget(weekNumber, 7, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 1, 1, 1);

        previousDay = new QPushButton(gridLayoutWidget);
        previousDay->setObjectName(QString::fromUtf8("previousDay"));

        gridLayout->addWidget(previousDay, 3, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        isLeap = new QPushButton(gridLayoutWidget);
        isLeap->setObjectName(QString::fromUtf8("isLeap"));

        gridLayout->addWidget(isLeap, 6, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        date = new QLineEdit(gridLayoutWidget);
        date->setObjectName(QString::fromUtf8("date"));

        gridLayout->addWidget(date, 1, 0, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMouseTracking(false);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        warning = new QLabel(centralwidget);
        warning->setObjectName(QString::fromUtf8("warning"));
        warning->setGeometry(QRect(0, 400, 801, 20));
        warning->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dates", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "File not chosen", nullptr));
        resetTable->setText(QCoreApplication::translate("MainWindow", "Select .txt", nullptr));
        addDate->setText(QCoreApplication::translate("MainWindow", "Add Date", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Delete Date", nullptr));
        nextDay->setText(QCoreApplication::translate("MainWindow", "NextDay", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "undefined", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "undefined", nullptr));
        duration->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        daysTillYourBirthday->setText(QCoreApplication::translate("MainWindow", "DaysTillYourBirthday", nullptr));
        weekNumber->setText(QCoreApplication::translate("MainWindow", "WeekNumber", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "undefined", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "undefined", nullptr));
        previousDay->setText(QCoreApplication::translate("MainWindow", "PreviousDay", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "undefined", nullptr));
        isLeap->setText(QCoreApplication::translate("MainWindow", "IsLeap", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "undefined", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select method", nullptr));
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

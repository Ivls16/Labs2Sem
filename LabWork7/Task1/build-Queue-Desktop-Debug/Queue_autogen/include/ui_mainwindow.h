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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QListWidget *listQueue;
    QHBoxLayout *inputLayout;
    QLineEdit *lineEditValue;
    QPushButton *buttonPush;
    QPushButton *buttonPop;
    QGridLayout *infoLayout;
    QLabel *labelSize;
    QLabel *labelEmpty;
    QLabel *labelFront;
    QLabel *labelBack;
    QHBoxLayout *taskLayout;
    QPushButton *buttonTask;
    QTextEdit *textTask;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        listQueue = new QListWidget(centralwidget);
        listQueue->setObjectName(QString::fromUtf8("listQueue"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        listQueue->setFont(font);
        listQueue->setStyleSheet(QString::fromUtf8("\n"
"        QListWidget {\n"
"            background-color: #e6e6fa;\n"
"            color: #9370db;\n"
"            border: 2px solid #d8bfd8;\n"
"            border-radius: 12px;\n"
"            padding: 10px;\n"
"        }\n"
"       "));

        mainLayout->addWidget(listQueue);

        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName(QString::fromUtf8("inputLayout"));
        lineEditValue = new QLineEdit(centralwidget);
        lineEditValue->setObjectName(QString::fromUtf8("lineEditValue"));
        lineEditValue->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              border: 2px solid #b0c4de;\n"
"              border-radius: 10px;\n"
"              padding: 6px;\n"
"              background-color: #f0f8ff;\n"
"              color: #6a5acd;\n"
"              font-weight: bold;\n"
"          }\n"
"         "));

        inputLayout->addWidget(lineEditValue);

        buttonPush = new QPushButton(centralwidget);
        buttonPush->setObjectName(QString::fromUtf8("buttonPush"));
        buttonPush->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                                stop:0 #b0e0e6, stop:1 #dda0dd);\n"
"              color: #4b0082;\n"
"              font-weight: bold;\n"
"              padding: 6px 12px;\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0ffff;\n"
"          }\n"
"         "));

        inputLayout->addWidget(buttonPush);

        buttonPop = new QPushButton(centralwidget);
        buttonPop->setObjectName(QString::fromUtf8("buttonPop"));
        buttonPop->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                                stop:0 #b0e0e6, stop:1 #dda0dd);\n"
"              color: #4b0082;\n"
"              font-weight: bold;\n"
"              padding: 6px 12px;\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0ffff;\n"
"          }\n"
"         "));

        inputLayout->addWidget(buttonPop);


        mainLayout->addLayout(inputLayout);

        infoLayout = new QGridLayout();
        infoLayout->setObjectName(QString::fromUtf8("infoLayout"));
        labelSize = new QLabel(centralwidget);
        labelSize->setObjectName(QString::fromUtf8("labelSize"));
        labelSize->setStyleSheet(QString::fromUtf8("\n"
"          QLabel {\n"
"              color: #6a5acd;\n"
"              font: bold 14pt \"Segoe UI\";\n"
"              background-color: #f8f8ff;\n"
"              padding: 4px;\n"
"              border-radius: 6px;\n"
"          }\n"
"         "));

        infoLayout->addWidget(labelSize, 0, 0, 1, 1);

        labelEmpty = new QLabel(centralwidget);
        labelEmpty->setObjectName(QString::fromUtf8("labelEmpty"));
        labelEmpty->setStyleSheet(QString::fromUtf8("\n"
"          QLabel {\n"
"              color: #6a5acd;\n"
"              font: bold 14pt \"Segoe UI\";\n"
"              background-color: #f8f8ff;\n"
"              padding: 4px;\n"
"              border-radius: 6px;\n"
"          }\n"
"         "));

        infoLayout->addWidget(labelEmpty, 0, 1, 1, 1);

        labelFront = new QLabel(centralwidget);
        labelFront->setObjectName(QString::fromUtf8("labelFront"));
        labelFront->setStyleSheet(QString::fromUtf8("\n"
"          QLabel {\n"
"              color: #6a5acd;\n"
"              font: bold 14pt \"Segoe UI\";\n"
"              background-color: #f8f8ff;\n"
"              padding: 4px;\n"
"              border-radius: 6px;\n"
"          }\n"
"         "));

        infoLayout->addWidget(labelFront, 1, 0, 1, 1);

        labelBack = new QLabel(centralwidget);
        labelBack->setObjectName(QString::fromUtf8("labelBack"));
        labelBack->setStyleSheet(QString::fromUtf8("\n"
"          QLabel {\n"
"              color: #6a5acd;\n"
"              font: bold 14pt \"Segoe UI\";\n"
"              background-color: #f8f8ff;\n"
"              padding: 4px;\n"
"              border-radius: 6px;\n"
"          }\n"
"         "));

        infoLayout->addWidget(labelBack, 1, 1, 1, 1);


        mainLayout->addLayout(infoLayout);

        taskLayout = new QHBoxLayout();
        taskLayout->setObjectName(QString::fromUtf8("taskLayout"));
        buttonTask = new QPushButton(centralwidget);
        buttonTask->setObjectName(QString::fromUtf8("buttonTask"));
        buttonTask->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                                stop:0 #b0e0e6, stop:1 #dda0dd);\n"
"              color: #4b0082;\n"
"              font-weight: bold;\n"
"              padding: 6px 12px;\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0ffff;\n"
"          }\n"
"         "));

        taskLayout->addWidget(buttonTask);

        textTask = new QTextEdit(centralwidget);
        textTask->setObjectName(QString::fromUtf8("textTask"));
        textTask->setMinimumSize(QSize(0, 55));
        textTask->setMaximumSize(QSize(16777215, 55));
        textTask->setStyleSheet(QString::fromUtf8("\n"
"          QTextEdit {\n"
"              background-color: #f8f8ff;\n"
"              color: #4b0082;\n"
"              font: bold 10pt \"Segoe UI\";\n"
"              border: 1px solid #d8bfd8;\n"
"              border-radius: 8px;\n"
"              padding: 6px;\n"
"          }\n"
"         "));
        textTask->setReadOnly(true);

        taskLayout->addWidget(textTask);


        mainLayout->addLayout(taskLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\360\237\222\255 Dreamcore Queue \360\237\222\255", nullptr));
        lineEditValue->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276 \360\237\222\253", nullptr));
        buttonPush->setText(QCoreApplication::translate("MainWindow", "Push \360\237\214\240", nullptr));
        buttonPop->setText(QCoreApplication::translate("MainWindow", "Pop \360\237\222\224", nullptr));
        labelSize->setText(QCoreApplication::translate("MainWindow", "Size: 0", nullptr));
        labelEmpty->setText(QCoreApplication::translate("MainWindow", "Empty: true", nullptr));
        labelFront->setText(QCoreApplication::translate("MainWindow", "Front: -", nullptr));
        labelBack->setText(QCoreApplication::translate("MainWindow", "Back: -", nullptr));
        buttonTask->setText(QCoreApplication::translate("MainWindow", "Task \360\237\222\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QGroupBox *groupBoxMenu;
    QVBoxLayout *menuLayout;
    QComboBox *comboBox;
    QGroupBox *groupBoxInput;
    QVBoxLayout *inputLayout;
    QTextEdit *textEdit;
    QGroupBox *groupBoxOutput;
    QVBoxLayout *outputLayout;
    QTextEdit *textOutput;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        groupBoxMenu = new QGroupBox(centralwidget);
        groupBoxMenu->setObjectName(QString::fromUtf8("groupBoxMenu"));
        groupBoxMenu->setStyleSheet(QString::fromUtf8("\n"
"  QGroupBox {\n"
"      background-color: #ffe6f0;\n"
"      color: #d63384;\n"
"      font-family: \"Comic Sans MS\";\n"
"      font-weight: bold;\n"
"      font-size: 14pt;\n"
"      border: 2px solid #ff69b4;\n"
"      border-radius: 10px;\n"
"      margin-top: 30px;\n"
"  }\n"
"  QGroupBox::title {\n"
"      subcontrol-origin: margin;\n"
"      subcontrol-position: top center;\n"
"      padding: 8px 12px;\n"
"      background-color: #ffccf9;\n"
"      color: #d63384;\n"
"      border: 1px solid #ff69b4;\n"
"      border-radius: 5px;\n"
"  }\n"
""));
        menuLayout = new QVBoxLayout(groupBoxMenu);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        comboBox = new QComboBox(groupBoxMenu);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"    background-color: #fff0f5;\n"
"    color: #d63384;\n"
"    font-family: \"Comic Sans MS\";\n"
"    font-size: 11pt;\n"
"    border: 1px solid #ff69b4;\n"
"    border-radius: 6px;\n"
"    padding: 4px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffe6f0;\n"
"    color: #ff1493;\n"
"    selection-background-color: #ffb6c1;\n"
"}\n"
"          "));

        menuLayout->addWidget(comboBox);


        mainLayout->addWidget(groupBoxMenu);

        groupBoxInput = new QGroupBox(centralwidget);
        groupBoxInput->setObjectName(QString::fromUtf8("groupBoxInput"));
        groupBoxInput->setStyleSheet(QString::fromUtf8("\n"
"QGroupBox {\n"
"    background-color: #fff0f5;\n"
"    border: 1px solid #ff69b4;\n"
"    border-radius: 8px;\n"
"}\n"
"       "));
        inputLayout = new QVBoxLayout(groupBoxInput);
        inputLayout->setObjectName(QString::fromUtf8("inputLayout"));
        textEdit = new QTextEdit(groupBoxInput);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit {\n"
"    background-color: #fffafc;\n"
"    color: #c71585;\n"
"    font-family: \"Comic Sans MS\";\n"
"    font-size: 11pt;\n"
"    border: 1px solid #ff69b4;\n"
"    border-radius: 6px;\n"
"}\n"
"          "));

        inputLayout->addWidget(textEdit);


        mainLayout->addWidget(groupBoxInput);

        groupBoxOutput = new QGroupBox(centralwidget);
        groupBoxOutput->setObjectName(QString::fromUtf8("groupBoxOutput"));
        groupBoxOutput->setStyleSheet(QString::fromUtf8("\n"
"QGroupBox {\n"
"    background-color: #ffe6f0;\n"
"    border: 1px solid #ff69b4;\n"
"    border-radius: 8px;\n"
"}\n"
"       "));
        outputLayout = new QVBoxLayout(groupBoxOutput);
        outputLayout->setObjectName(QString::fromUtf8("outputLayout"));
        textOutput = new QTextEdit(groupBoxOutput);
        textOutput->setObjectName(QString::fromUtf8("textOutput"));
        textOutput->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit {\n"
"    background-color: #fff0f5;\n"
"    color: #800040;\n"
"    font-family: \"Comic Sans MS\";\n"
"    font-size: 11pt;\n"
"    border: 1px solid #ff69b4;\n"
"    border-radius: 6px;\n"
"}\n"
"          "));
        textOutput->setReadOnly(true);

        outputLayout->addWidget(textOutput);


        mainLayout->addWidget(groupBoxOutput);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #ffb6c1;\n"
"    color: #8b008b;\n"
"    border: 2px solid #ff69b4;\n"
"    border-radius: 8px;\n"
"    font-family: \"Comic Sans MS\";\n"
"    font-size: 10pt;\n"
"    padding: 6px 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #ffc0cb;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #ff69b4;\n"
"    color: #ffffff;\n"
"}\n"
"       "));

        mainLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Barbie Monitor", nullptr));
        groupBoxMenu->setTitle(QCoreApplication::translate("MainWindow", "\360\237\222\226 CAM MENU \360\237\222\226", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "0 - Power Down", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1 - Log text to file", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2 - Read text from file", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3 - Write char array", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4 - Read char array", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5 - Save struct to file", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6 - Load struct from file", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "7 - Save struct to BIN", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "8 - Load struct from BIN", nullptr));

        groupBoxInput->setTitle(QString());
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type your Barbie command...", nullptr));
        groupBoxOutput->setTitle(QString());
        textOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\342\234\250 Logs from BarbieCam...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\342\234\250 EXECUTE \342\234\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

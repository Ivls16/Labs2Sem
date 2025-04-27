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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QTreeWidget *treeWidget;
    QHBoxLayout *inputLayout;
    QLineEdit *lineEditKey;
    QLineEdit *lineEditValue;
    QGridLayout *buttonLayout;
    QPushButton *buttonAdd;
    QPushButton *buttonDelete;
    QPushButton *buttonBalance;
    QPushButton *buttonFind;
    QPushButton *buttonPreorder;
    QPushButton *buttonPostorder;
    QPushButton *buttonInorder;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setHeaderHidden(true);
        treeWidget->setStyleSheet(QString::fromUtf8("\n"
"        QTreeWidget {\n"
"            background-color: #f8f8ff;\n"
"            color: #6a5acd;\n"
"            border: 2px solid #d8bfd8;\n"
"            border-radius: 12px;\n"
"            padding: 6px;\n"
"        }\n"
"       "));
        treeWidget->setMinimumHeight(250);

        mainLayout->addWidget(treeWidget);

        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName(QString::fromUtf8("inputLayout"));
        lineEditKey = new QLineEdit(centralwidget);
        lineEditKey->setObjectName(QString::fromUtf8("lineEditKey"));
        lineEditKey->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              background-color: #f0f8ff;\n"
"              color: #6a5acd;\n"
"              font: bold 12pt \"Segoe UI\";\n"
"              border: 2px solid #b0c4de;\n"
"              border-radius: 10px;\n"
"              padding: 6px;\n"
"          }\n"
"         "));

        inputLayout->addWidget(lineEditKey);

        lineEditValue = new QLineEdit(centralwidget);
        lineEditValue->setObjectName(QString::fromUtf8("lineEditValue"));
        lineEditValue->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              background-color: #f0f8ff;\n"
"              color: #6a5acd;\n"
"              font: bold 12pt \"Segoe UI\";\n"
"              border: 2px solid #b0c4de;\n"
"              border-radius: 10px;\n"
"              padding: 6px;\n"
"          }\n"
"         "));

        inputLayout->addWidget(lineEditValue);


        mainLayout->addLayout(inputLayout);

        buttonLayout = new QGridLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        buttonAdd = new QPushButton(centralwidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        buttonAdd->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #dda0dd;\n"
"              color: #4b0082;\n"
"              font: bold 11pt \"Segoe UI\";\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"              padding: 6px 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e6e6fa;\n"
"          }\n"
"         "));
        buttonAdd->setMinimumHeight(55);

        buttonLayout->addWidget(buttonAdd, 0, 0, 1, 1);

        buttonDelete = new QPushButton(centralwidget);
        buttonDelete->setObjectName(QString::fromUtf8("buttonDelete"));
        buttonDelete->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #dda0dd;\n"
"              color: #4b0082;\n"
"              font: bold 11pt \"Segoe UI\";\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"              padding: 6px 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e6e6fa;\n"
"          }\n"
"         "));
        buttonDelete->setMinimumHeight(55);

        buttonLayout->addWidget(buttonDelete, 0, 1, 1, 1);

        buttonBalance = new QPushButton(centralwidget);
        buttonBalance->setObjectName(QString::fromUtf8("buttonBalance"));
        buttonBalance->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #dda0dd;\n"
"              color: #4b0082;\n"
"              font: bold 11pt \"Segoe UI\";\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"              padding: 6px 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e6e6fa;\n"
"          }\n"
"         "));
        buttonBalance->setMinimumHeight(55);

        buttonLayout->addWidget(buttonBalance, 1, 0, 1, 1);

        buttonFind = new QPushButton(centralwidget);
        buttonFind->setObjectName(QString::fromUtf8("buttonFind"));
        buttonFind->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #dda0dd;\n"
"              color: #4b0082;\n"
"              font: bold 11pt \"Segoe UI\";\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"              padding: 6px 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e6e6fa;\n"
"          }\n"
"         "));
        buttonFind->setMinimumHeight(55);

        buttonLayout->addWidget(buttonFind, 1, 1, 1, 1);

        buttonPreorder = new QPushButton(centralwidget);
        buttonPreorder->setObjectName(QString::fromUtf8("buttonPreorder"));
        buttonPreorder->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #dda0dd;\n"
"              color: #4b0082;\n"
"              font: bold 11pt \"Segoe UI\";\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"              padding: 6px 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e6e6fa;\n"
"          }\n"
"         "));
        buttonPreorder->setMinimumHeight(55);

        buttonLayout->addWidget(buttonPreorder, 2, 0, 1, 1);

        buttonPostorder = new QPushButton(centralwidget);
        buttonPostorder->setObjectName(QString::fromUtf8("buttonPostorder"));
        buttonPostorder->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #dda0dd;\n"
"              color: #4b0082;\n"
"              font: bold 11pt \"Segoe UI\";\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"              padding: 6px 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e6e6fa;\n"
"          }\n"
"         "));
        buttonPostorder->setMinimumHeight(55);

        buttonLayout->addWidget(buttonPostorder, 2, 1, 1, 1);

        buttonInorder = new QPushButton(centralwidget);
        buttonInorder->setObjectName(QString::fromUtf8("buttonInorder"));
        buttonInorder->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #dda0dd;\n"
"              color: #4b0082;\n"
"              font: bold 11pt \"Segoe UI\";\n"
"              border-radius: 12px;\n"
"              border: 1px solid #d8bfd8;\n"
"              padding: 6px 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e6e6fa;\n"
"          }\n"
"         "));
        buttonInorder->setMinimumHeight(55);

        buttonLayout->addWidget(buttonInorder, 3, 0, 1, 2);


        mainLayout->addLayout(buttonLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\360\237\222\255 Dreamcore Tree \360\237\222\255", nullptr));
        lineEditKey->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\273\321\216\321\207 \360\237\224\221", nullptr));
        lineEditValue->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \360\237\214\270", nullptr));
        buttonAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\320\267\320\265\320\273 \360\237\214\261", nullptr));
        buttonDelete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\320\267\320\265\320\273 \360\237\215\202", nullptr));
        buttonBalance->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\273\320\260\320\275\321\201\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \342\232\226\357\270\217", nullptr));
        buttonFind->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \360\237\224\215", nullptr));
        buttonPreorder->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\271 \320\276\320\261\321\205\320\276\320\264 \342\217\251", nullptr));
        buttonPostorder->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\271 \320\276\320\261\321\205\320\276\320\264 \342\217\252", nullptr));
        buttonInorder->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\274\320\274\320\265\321\202\321\200\320\270\321\207\320\275\321\213\320\271 \320\276\320\261\321\205\320\276\320\264 \360\237\224\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

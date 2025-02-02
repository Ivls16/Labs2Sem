#include <QLabel>
#include <QTableWidget>
#include <QObject>
#include <QFileDialog>
#include <algorithm>
#include <QSaveFile>
#include <QMessageBox>
#include <QTimeEdit>
#include "mainwindow.h"

class Database: public QObject
{
Q_OBJECT
private:
    MainWindow* parent;
    bool type, fileSetted;
    QString fileName, baseName;
    QStringList columnNames;
    QLabel *header;
    QTableWidget *table;
    QPushButton *openButton, *saveButton, *addButton, *deleteButton;
public:
    Database();
    Database(MainWindow*, bool, QLabel*, QString, QTableWidget*, QStringList, QPushButton*, QPushButton*, QPushButton*, QPushButton*);

    void ResetArray();
private slots:
    void OpenFile();
    void AddLine();
    void DeleteSelected();
    void SaveFile();
    void UpdateComboBox();
};

QString TimeIntervalString(QString, QString);


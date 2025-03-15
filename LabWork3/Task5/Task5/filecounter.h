#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include "filecounterinterface.h"
#include <QFileDialog>
#include <QDesktopServices>

class FileCounter: public QMainWindow
{
    Q_OBJECT
public:
    FileCounter(QWidget* parent = nullptr);
private:
    FileCounterInterface *interface;

    void CountAll(const QString&, int&, int&);
private slots:
    void CheckDirectory();
    void OpenFile();
};

#endif // FILECOUNTER_H

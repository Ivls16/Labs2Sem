#ifndef FILECOUNTERINTERFACE_H
#define FILECOUNTERINTERFACE_H

#include <QPushButton>
#include <QLabel>
#include <QMainWindow>

class FileCounterInterface: public QMainWindow
{
public:
    FileCounterInterface(QWidget* parent = nullptr);

    QPushButton* ActivationButton();
    QPushButton* OpenButton();
    QLabel* DirectoryText();
    QLabel* FileCountText();
private:
    QPushButton *activate, *openFile;
    QLabel *directory, *fileCountLabel;
};

#endif // FILECOUNTERINTERFACE_H

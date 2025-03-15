#include "filecounterinterface.h"

FileCounterInterface::FileCounterInterface(QWidget* parent): QMainWindow(parent)
{
    activate = new QPushButton(parent);
    activate->setText("choose"); activate->move(50, 150);
    openFile = new QPushButton(parent);
    openFile->setText("open"); openFile->move(160, 150);
    directory = new QLabel(parent);
    directory->move(50, 50); directory->setFixedWidth(500);
    fileCountLabel = new QLabel(parent);
    fileCountLabel->move(50, 100); fileCountLabel->setFixedWidth(500);

    directory->setText("directory is not chosen");
    fileCountLabel->setText("files: -1, folders: -1");
}

QPushButton* FileCounterInterface::ActivationButton()
{
    return activate;
}

QPushButton* FileCounterInterface::OpenButton()
{
    return openFile;
}

QLabel* FileCounterInterface::DirectoryText() {
    return directory;
}

QLabel* FileCounterInterface::FileCountText() {
    return fileCountLabel;
}

#include "filecounter.h"

FileCounter::FileCounter(QWidget* parent): QMainWindow(parent)
{
    interface = new FileCounterInterface(parent);
    connect(interface->ActivationButton(), &QPushButton::clicked, this, &FileCounter::CheckDirectory);
    connect(interface->OpenButton(), &QPushButton::clicked, this, &FileCounter::OpenFile);
}

void FileCounter::CountAll(const QString &directory, int &folderCount, int &fileCount)
{
    QDir dir(directory);

    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QFileInfo &entry : list) {
        if (entry.isDir()) {
            folderCount++;
            CountAll(entry.absoluteFilePath(), folderCount, fileCount);
        } else if (entry.isFile()) {
            fileCount++;
        }
    }
}

void FileCounter::CheckDirectory()
{
    QString directoryPath = QFileDialog::getExistingDirectory(nullptr, "choose directory");
    if (directoryPath.isEmpty())
    {
        interface->DirectoryText()->setText("directory is not chosen");
        interface->FileCountText()->setText("files: -1, folders: -1");
        return;
    }
    interface->DirectoryText()->setText(directoryPath);
    int folders = 0, files = 0;
    CountAll(directoryPath, folders, files);
    interface->FileCountText()->setText("files: " + QString::number(files) + " folders: " + QString::number(folders));
}

void FileCounter::OpenFile()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "choose file");
    if (!filePath.isEmpty()) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

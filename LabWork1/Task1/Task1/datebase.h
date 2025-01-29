#include "date.h"
#include <QFileDialog>
#include <QLabel>

class DateBase {
private:
    bool chosen;
    std::fstream dateBase;
    QString fileName;
public:
    DateBase() {}

    void Init(bool=false);
    void Close();
    void Write(int, std::string);
    bool ChosenFile();
    QString GetFileName();
    Date ReadDate();
};

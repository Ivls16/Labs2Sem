#pragma once
#include "datebase.h"
#include <QFileDialog>
#include <QLabel>

Date* ReadFromFile(int&, QLabel*, bool=false);
DateBase* Dates();

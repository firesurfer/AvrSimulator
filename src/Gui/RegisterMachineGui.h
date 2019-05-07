#ifndef REGISTERMACHINEGUI_H
#define REGISTERMACHINEGUI_H

#include <QtWidgets/QApplication>
#include "MainWindow.h"

class RegisterMachineGui
{
public:
    RegisterMachineGui(int _argc, char** _argv);
    int exec();
private:
    int argc;
    char** argv;
};

#endif // REGISTERMACHINEGUI_H

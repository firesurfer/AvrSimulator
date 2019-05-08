/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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

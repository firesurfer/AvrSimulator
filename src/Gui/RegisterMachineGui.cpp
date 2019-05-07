#include "RegisterMachineGui.h"

RegisterMachineGui::RegisterMachineGui(int _argc, char **_argv):
    argc(_argc),
    argv(_argv)
{

}

int RegisterMachineGui::exec()
{
    QApplication app(argc,argv);

    MainWindow window;
    window.show();
    return app.exec();
}

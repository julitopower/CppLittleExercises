#include <iostream>
#include <Qt/QtNetwork>
#include "Window.hpp"
#include "QtCore"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Hello World!" << endl;

    QApplication app(argc, argv);

    ui::Window w;

    w.show();

    return app.exec();
}


#include <iostream>
#include "Window.hpp"
#include "QtCore"
#include "QApplication"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Starting Demo QT application" << endl;

    QApplication app(argc, argv);
    ui::Window w;
    w.show();
    return app.exec();
}


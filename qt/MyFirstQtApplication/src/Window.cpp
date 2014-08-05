#include "Window.hpp"
#include <iostream>

namespace ui {

Window::Window() {
    std::cout << "Constructing Window" << endl;

    setWindowTitle("MyQTWindow");
    setGeometry(100,100,600,600);
    createActions();
    createMenus();
}

void Window::createActions() {
    exitAction = new QAction("Exit", this);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));
}

void Window::createMenus() {
    menubar = new QMenuBar(this);
    fileMenu = new QMenu(menubar);
    fileMenu->setTitle("&File");

    menubar->addMenu(fileMenu);
    fileMenu->addAction(exitAction);
}

void Window::exit() {
    this->close();
}

void Window::nothing() {
    std::cout << "Doing nothing" << std::endl ;
}

}

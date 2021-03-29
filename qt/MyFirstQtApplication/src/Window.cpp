#include "Window.hpp"
#include <iostream>
#include "QAction"
#include "QMenuBar"

namespace ui {

Window::Window() {
    std::cout << "Constructing Window" << std::endl;

    setWindowTitle("MyQTWindow");
    setGeometry(100,100,600,600);
    createActions();
    createMenus();
    std::cout << "Created menus" << std::endl;
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
    std::cout << "Closing the window" << std::endl;
    this->close();
}

void Window::nothing() {
    std::cout << "Doing nothing" << std::endl ;
}

} // namespace ui

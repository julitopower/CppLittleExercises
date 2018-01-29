#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>

namespace ui {

class Window : public QMainWindow{
    Q_OBJECT

public:
    explicit Window();
    void nothing();

private slots:
    void exit();

private:
    QMenuBar * menubar;
    QMenu * fileMenu;
    QAction * exitAction;

    void createActions();
    void createMenus();

};

}

#endif // WINDOW_HPP

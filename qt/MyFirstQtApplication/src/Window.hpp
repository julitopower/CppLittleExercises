#pragma once

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

} // namespace ui

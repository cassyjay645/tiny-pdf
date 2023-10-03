#include <iostream>
#include "include/mainwindow.hpp"

#include <QtWidgets/QApplication>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    auto win = new MainWindow;
    win->show();

    return app.exec();
}
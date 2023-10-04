#include <iostream>
#include "include/mainwindow.hpp"

#include <QtWidgets/QApplication>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    auto win = new MainWindow;
    win->show();
    if(argc >= 1)
    win->open_file(QUrl::fromLocalFile(argv[1]));

    return app.exec();
}
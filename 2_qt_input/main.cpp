#include <QApplication>
#include "mainwindow.h"


int main(
    int argc,
    char *argv[]
) {
    // 1. init Qt app environment
    QApplication app(argc, argv);

    // 2. instantiate custom window defined in mainwindow.h
    MainWindow window;
    window.show();

    // 3. start Qt event loop
    return app.exec();
}
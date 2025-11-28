#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]) {
    // 1. init Qt app environment
    QApplication app(argc, argv);

    // 2. instantiate custom window defined in mainwindow.h containing web view
    MainWindow window;
    window.setWindowTitle("Expense Entry App - Qt WebEngine");
    window.resize(1024, 768); // A normal resolution for the web frontend
    window.show();

    // 3. start Qt event loop
    return app.exec();
}
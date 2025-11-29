#include <QApplication>
#include <QWebEngineProfile>
#include <QWebEngineUrlScheme>
#include <QCoreApplication>
#include "mainwindow.h"
#include "urlschemehandler.h"


int main(int argc, char *argv[]) {
    // 0. CRITICAL: Register custom URL scheme BEFORE QApplication
    QWebEngineUrlScheme scheme("app");
    scheme.setFlags(QWebEngineUrlScheme::SecureScheme |
                   QWebEngineUrlScheme::LocalScheme |
                   QWebEngineUrlScheme::LocalAccessAllowed |
                   QWebEngineUrlScheme::CorsEnabled);
    QWebEngineUrlScheme::registerScheme(scheme);

    // 1. Set the QtWebEngineProcess path before creating QApplication
    // This tells Qt where to find the WebEngine helper process
    qputenv("QTWEBENGINEPROCESS_PATH", "/usr/lib/qt6/libexec/QtWebEngineProcess");


    // 2. init Qt app environment
    QApplication app(argc, argv);

    // 3. Register the custom scheme handler
    QString basePath = QCoreApplication::applicationDirPath() + "/expense-frontend/dist";
    LocalFileSchemeHandler *handler = new LocalFileSchemeHandler(basePath);
    QWebEngineProfile::defaultProfile()->installUrlSchemeHandler("app", handler);

    // 4. instantiate custom window defined in mainwindow.h containing web view
    MainWindow window;
    window.setWindowTitle("Expense Entry App - Qt WebEngine");
    window.resize(1024, 768); // A normal resolution for the web frontend
    window.show();

    // 5. start Qt event loop
    return app.exec();
}
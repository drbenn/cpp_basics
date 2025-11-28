#include "mainwindow.h"
#include <QUrl>
#include <QFile>
#include <QCoreApplication>
#include <QMessageBox> // Used for user feedback if the file load fails

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 1. Instantiate the QWebEngineView and set this MainWindow as its parent
    webView = new QWebEngineView(this);
    
    // 2. Set the webView to take up the entire area of the main window
    setCentralWidget(webView);

    // 3. Construct the absolute path to the local HTML file (index.html)
    // CRITICAL FIX: We now look inside the 'dist' directory, which is the standard 
    // output folder for a 'npm run build' command in a Vite project.
    QString currentDir = QCoreApplication::applicationDirPath();
    // Assuming the 'dist' folder is placed alongside the executable
    QString htmlFilePath = currentDir + "expense_frontend/dist/index.html"; 
    
    // Convert the local file path to a QUrl for the web engine
    QUrl localFileUrl = QUrl::fromLocalFile(htmlFilePath);

    // 4. Check for the file existence and load it
    if (QFile::exists(htmlFilePath)) {
        webView->load(localFileUrl);
    } else {
        // If the file is missing, display a critical error message
        QMessageBox::critical(this, "File Error", 
            "Failed to find the frontend file: 'index.html'. Please ensure the Vite 'dist' folder is correctly deployed next to the executable. "
            "Path checked: " + htmlFilePath
        );
    }
}

MainWindow::~MainWindow()
{
    // The webView memory is managed by Qt's object tree (since 'this' was passed as parent)
}
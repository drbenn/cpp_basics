#include "mainwindow.h"
#include <QUrl>
#include <QFile>
#include <QCoreApplication>
#include <QMessageBox>
#include <QDebug>
#include <QWebEngineSettings>
#include <QWebEnginePage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 1. Instantiate the QWebEngineView and set this MainWindow as its parent
    webView = new QWebEngineView(this);
    
    // Enable developer tools and other useful settings
    webView->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    webView->settings()->setAttribute(QWebEngineSettings::ErrorPageEnabled, true);
    webView->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    
    // 2. Set the webView to take up the entire area of the main window
    setCentralWidget(webView);

    // 3. Construct the absolute path to the local HTML file (index.html)
    QString currentDir = QCoreApplication::applicationDirPath();
    
    // folder name to expense-frontend (with hyphen, not underscore)
    QString htmlFilePath = currentDir + "/expense-frontend/dist/index.html"; 
    
    // Debug output to help troubleshoot
    qDebug() << "Looking for HTML file at:" << htmlFilePath;
    
    // Convert the local file path to a QUrl for the web engine
    QUrl localFileUrl = QUrl::fromLocalFile(htmlFilePath);

    // 4. Check for the file existence and load it
    if (QFile::exists(htmlFilePath)) {
        qDebug() << "File found! Loading...";
        webView->load(localFileUrl);
    } else {
        // If the file is missing, display a critical error message
        qDebug() << "File NOT found!";
        QString errorMsg = "Failed to find the frontend file: 'index.html'. "
                          "Please ensure the Vite 'dist' folder is correctly deployed next to the executable.\n\n"
                          "Path checked: " + htmlFilePath;
        QMessageBox::critical(this, "File Error", errorMsg);
    }
}

MainWindow::~MainWindow()
{
    // The webView memory is managed by Qt's object tree (since 'this' was passed as parent)
}
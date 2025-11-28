#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// QWebEngineView is the essential component needed to display HTML/CSS/JS content
#include <QWebEngineView> 

class MainWindow : public QMainWindow 
{
    Q_OBJECT

public:
    /**
     *  @brief constructor for main window
     *  @param parent The parent widget
     */
     explicit MainWindow(QWidget *parent = nullptr);
    // Destructor
    ~MainWindow();

private:
    // Declaration of the pointer to the WebEngine View. 
    // This will be instantiated and configured in mainwindow.cpp.
    QWebEngineView *webView;
};

#endif // MAINWINDOW_H
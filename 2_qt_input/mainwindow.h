#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDoubleValidator>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    /**
     *  @brief constructor for main window
     *  @param parent The parent widget
     */
     explicit MainWindow(QWidget *parent = nullptr);

private slots:
    /**
        @brief Slot function when log button is clicked
        contains logic for validation and display
    */
    void handleLog();

private:
    // UI components
    QLineEdit *descriptionInput;
    QLineEdit *amountInput;
    QPushButton *logButton;
};

#endif // MAINWINDOW_H
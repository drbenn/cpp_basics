#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QLocale>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Expense Entry");
    setMinimumWidth(350);

    // widget init
    descriptionInput = new QLineEdit();
    descriptionInput->setPlaceholderText("Enter description:");

    amountInput = new QLineEdit();
    amountInput->setPlaceholderText("Enter amount:");

    // setup double/amount validator
    QDoubleValidator* validator = new QDoubleValidator(0.0, 999999.99, 2, this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    amountInput->setValidator(validator);

    logButton = new QPushButton("Log Transaction");
    logButton->setMinimumHeight(40);

    // Layout setup
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Description:"));
    mainLayout->addWidget(descriptionInput);
    mainLayout->addSpacing(15);
    mainLayout->addWidget(new QLabel("Amount ($):"));
    mainLayout->addWidget(amountInput);
    mainLayout->addSpacing(25);
    mainLayout->addWidget(logButton);

    // connection signal/slot
    // connects buttons clicked signal to the private slot with handleLog()
    connect(logButton, &QPushButton::clicked, this, &MainWindow::handleLog);
}

// implementation of slot function handleLog
void MainWindow::handleLog() {
    QString description = descriptionInput->text().trimmed();
    QString amountText = amountInput->text().trimmed();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Transaction Result");

    // 1. Basic Validation
    if (description.isEmpty() || amountText.isEmpty()) {
        msgBox.setText("Error: Both description and amount must be entered.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }

    // 2. Amount Conversion and Detailed Validation
    bool ok;
    // Use QLocale to correctly interpret the numeric input
    double amount = QLocale().toDouble(amountText, &ok);
    
    if (!ok) {
        msgBox.setText("Error: Invalid amount entered. Please use a numeric format.");
        msgBox.setIcon(QMessageBox::Critical);
    } else if (amount <= 0) {
        msgBox.setText("Error: Amount must be positive.");
        msgBox.setIcon(QMessageBox::Warning);
    } else {
        // Success: Display the results
        QString result = QString("Transaction Logged Successfully:\n\n"
                                 "Description: %1\n"
                                 "Amount: %2")
                                 .arg(description)
                                 .arg(QLocale().toString(amount, 'f', 2)); // Format to 2 decimal places

        msgBox.setText(result);
        msgBox.setIcon(QMessageBox::Information);

        // Clear inputs after successful log
        descriptionInput->clear();
        amountInput->clear();
    }

    msgBox.exec();
}
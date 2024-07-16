#include "MainWindow.h"
#include "PasswordGenerator.h"
#include "PasswordManager.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QClipboard>
#include <QApplication>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QFormLayout *formLayout = new QFormLayout();
    websiteEntry = new QLineEdit();
    emailEntry = new QLineEdit();
    emailEntry->setText("angela@gmail.com");
    passwordEntry = new QLineEdit();
    formLayout->addRow("Website:", websiteEntry);
    formLayout->addRow("Email/Username:", emailEntry);
    formLayout->addRow("Password:", passwordEntry);

    QPushButton *generateButton = new QPushButton("Generate Password");
    QPushButton *addButton = new QPushButton("Add");
    statusLabel = new QLabel();

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(generateButton);
    mainLayout->addWidget(addButton);
    mainLayout->addWidget(statusLabel);

    setCentralWidget(centralWidget);

    connect(generateButton, &QPushButton::clicked, this, &MainWindow::generatePassword);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::savePassword);
}

MainWindow::~MainWindow() {}

void MainWindow::generatePassword() {
    QString password = PasswordGenerator::generatePassword();
    passwordEntry->setText(password);
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(password);
    statusLabel->setText("Password copied to clipboard!");
}

void MainWindow::savePassword() {
    QString website = websiteEntry->text();
    QString email = emailEntry->text();
    QString password = passwordEntry->text();

    if(website.isEmpty() || password.isEmpty()) {
        QMessageBox::information(this, "Oops", "Please make sure you haven't left any fields empty.");
        return;
    }

    PasswordManager::savePassword(website, email, password);
    websiteEntry->clear();
    passwordEntry->clear();
    statusLabel->setText("Password saved!");
}

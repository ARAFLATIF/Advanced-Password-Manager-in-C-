#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void generatePassword();
    void savePassword();

private:
    QLineEdit *websiteEntry;
    QLineEdit *emailEntry;
    QLineEdit *passwordEntry;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H

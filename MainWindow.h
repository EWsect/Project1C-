#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QLabel* m_urlLabel;
    QLineEdit* m_urlLineEdit;
    QPushButton* m_sendButton;

private slots:
    void handleSendButtonClicked();
};

#endif // MAINWINDOW_H

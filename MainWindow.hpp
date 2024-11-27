#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include "sequences/ListSequence.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void appendItem();
    void removeLastItem();

private:
    MutableListSequence<int> list;
    QVBoxLayout *layout;
    QListWidget *listWidget;
    QLineEdit *inputField;
    QPushButton *appendButton;
    QPushButton *removeButton;

    void updateListWidget();
};

#endif // MAINWINDOW_H
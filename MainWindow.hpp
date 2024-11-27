#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include "sequences/ListSequence.hpp"
#include "pointers/shared_weak_ptr.hpp"


class MainWindow : public QMainWindow 
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    void appendItem();
    void removeLastItem();
    void insertAtItem();
    void eraseItem();

private:
    MutableListSequence<SharedPtr<int>> list;
    QVBoxLayout* layout;
    QListWidget* listWidget;
    QLineEdit* inputField;
    QLineEdit* indexField;
    QPushButton* appendButton;
    QPushButton* removeButton;
    QPushButton* insertAtButton;
    QPushButton* eraseButton;

    void updateListWidget();
};
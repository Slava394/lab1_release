#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), layout(new QVBoxLayout), listWidget(new QListWidget),
      inputField(new QLineEdit), indexField(new QLineEdit), appendButton(new QPushButton("Append")),
      removeButton(new QPushButton("Remove last")), insertAtButton(new QPushButton("Insert at")),
      eraseButton(new QPushButton("Erase at")) 
{
    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    layout->addWidget(listWidget);
    layout->addWidget(inputField);
    inputField->setPlaceholderText("Enter value");
    layout->addWidget(indexField);
    indexField->setPlaceholderText("Enter index");
    layout->addWidget(appendButton);
    layout->addWidget(removeButton);
    layout->addWidget(insertAtButton);
    layout->addWidget(eraseButton);
    centralWidget->setLayout(layout);

    connect(appendButton, &QPushButton::clicked, this, &MainWindow::appendItem);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeLastItem);
    connect(insertAtButton, &QPushButton::clicked, this, &MainWindow::insertAtItem);
    connect(eraseButton, &QPushButton::clicked, this, &MainWindow::eraseItem);

    updateListWidget();
}

void MainWindow::appendItem() 
{
    bool ok;
    int value = inputField->text().toInt(&ok);
    if (ok) 
    {
        list.Append(SharedPtr<int>(new int(value))); 
        inputField->clear();
        updateListWidget();
    }
}

void MainWindow::removeLastItem() 
{
    if (list.GetLength() != 0) 
    {
        list.RemoveLast();
        updateListWidget();
    }
}

void MainWindow::insertAtItem() 
{
    bool valueOk, indexOk;
    int value = inputField->text().toInt(&valueOk);
    int index = indexField->text().toInt(&indexOk);
    if (valueOk && indexOk && index >= 0 && index <= list.GetLength()) 
    {
        list.InsertAt(SharedPtr<int>(new int(value)), index);
        inputField->clear();
        indexField->clear();
        updateListWidget();
    }
}

void MainWindow::eraseItem() 
{
    bool ok;
    int index = indexField->text().toInt(&ok);
    if (ok && index >= 0 && index < list.GetLength()) 
    {
        list.Erase(index);
        indexField->clear();
        updateListWidget();
    }
}

void MainWindow::updateListWidget() 
{
    listWidget->clear();
    for (int index = 0; index < list.GetLength(); ++index) 
    {
        SharedPtr<int> sp = list[index];
        listWidget->addItem(QString::number(*sp)); 
    }
}
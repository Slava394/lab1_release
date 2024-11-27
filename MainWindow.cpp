#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), layout(new QVBoxLayout), listWidget(new QListWidget),
      inputField(new QLineEdit), appendButton(new QPushButton("Добавить")),
      removeButton(new QPushButton("Удалить последний")) {

    // Основной виджет
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    // Настройка интерфейса
    layout->addWidget(listWidget);
    layout->addWidget(inputField);
    layout->addWidget(appendButton);
    layout->addWidget(removeButton);

    centralWidget->setLayout(layout);

    // Подключение сигналов и слотов
    connect(appendButton, &QPushButton::clicked, this, &MainWindow::appendItem);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeLastItem);

    // Первоначальное обновление
    updateListWidget();
}

void MainWindow::appendItem() {
    bool ok;
    int value = inputField->text().toInt(&ok);
    if (ok) {
        list.Append(value);
        inputField->clear();
        updateListWidget();
    }
}

void MainWindow::removeLastItem() {
    if (list.GetLength() != 0) {
        list.RemoveLast();
        updateListWidget();
    }
}

void MainWindow::updateListWidget() {
    listWidget->clear();
    for (int i = 0; i < list.GetLength(); ++i) {
        listWidget->addItem(QString::number(list[i]));
    }
}

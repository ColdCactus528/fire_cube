#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Подключение кнопок к слотам
    connect(ui->btnAddSegment, &QPushButton::clicked, this, &MainWindow::addSegment);
    connect(ui->btnCopySegment, &QPushButton::clicked, this, &MainWindow::copySegment);
    connect(ui->btnDeleteSegment, &QPushButton::clicked, this, &MainWindow::deleteSegment);
    connect(ui->btnApply, &QPushButton::clicked, this, &MainWindow::applyChanges);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addSegment() {
    // Пример добавления строки
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    // Заполнение строки данными из полей ввода
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ui->lineEditName->text()));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ui->lineEditValue->text()));
}

void MainWindow::copySegment() {
    // Копирование выбранной строки
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow >= 0) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(currentRow, col);
            if (item) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(item->text()));
            }
        }
    }
}

void MainWindow::deleteSegment() {
    // Удаление выбранной строки
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow >= 0) {
        ui->tableWidget->removeRow(currentRow);
    }
}

void MainWindow::applyChanges() {
    // Пример обработки данных (можно сохранить данные в файл или передать куда-либо)
    qDebug() << "Changes applied!";
}

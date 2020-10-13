#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showColumnHeaders();
    QObject::connect(ui->startButton,SIGNAL(clicked(true)),this,SLOT(on_startButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    _fileName = _fileDialog.getOpenFileName().toStdString();
    emit startButtonPress();
}

void MainWindow::setRowCount(int count)
{
    if(ui){
        ui->tableInfoWidget->setRowCount(count);
    }
}

void MainWindow::addNewInfoOnScreen(const std::pair<QString,QString>* info)
{
    if(ui){
       int rowIndex = 0;
       int firstColumnIndex  = 0;
       int secondColumnIndex = 1;

       ui->tableInfoWidget->insertRow(ui->tableInfoWidget->rowCount());
       rowIndex = ui->tableInfoWidget->rowCount() - 1;

       ui->tableInfoWidget->setItem(rowIndex, firstColumnIndex, new QTableWidgetItem(info->first));
       ui->tableInfoWidget->setItem(rowIndex, secondColumnIndex, new QTableWidgetItem(info->second));
    }
}

void MainWindow::showColumnHeaders()
{
    ui->tableInfoWidget->insertRow(ui->tableInfoWidget->rowCount());
    ui->tableInfoWidget->setItem(0, 0, new QTableWidgetItem("Имя файла"));
    ui->tableInfoWidget->setItem(0, 1, new QTableWidgetItem("Размер, (байт)"));
}

std::string MainWindow::getFileName()
{
    return _fileName;
}

void MainWindow::cleanTable()
{
    size_t tableSize = ui->tableInfoWidget->rowCount();
    for(tableSize; tableSize > 1; tableSize--)
    {
        ui->tableInfoWidget->removeRow(tableSize);
    }

}

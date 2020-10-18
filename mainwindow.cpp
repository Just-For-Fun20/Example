#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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


std::string MainWindow::getFileName()
{
    return _fileName;
}

void MainWindow::tableViewInit(const std::vector<std::pair<QString, QString> > &data)
{
    TCustomTableModel *model = new TCustomTableModel();
    model->setData(data);
    ui->_tableView->setModel(model);
    ui->_tableView->horizontalHeader()->setVisible(true);
    ui->_tableView->show();
}


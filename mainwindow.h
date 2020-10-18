#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <utility>
#include <QFileDialog>
#include <string>
#include <vector>
#include "tcustomtablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    std::string getFileName();
    void tableViewInit(const std::vector< std::pair<QString, QString> > &data);
    ~MainWindow();

signals:
    void startButtonPress();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileDialog _fileDialog;
    std::string _fileName;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <utility>
#include <QFileDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addNewInfoOnScreen(const std::pair<QString,QString>* info);
    void setRowCount(int count);
    void showColumnHeaders();
    QString getFileName();
    void cleanTable();
    ~MainWindow();

signals:
    void startButtonPress();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileDialog _fileDialog;
    QString _fileName;
};
#endif // MAINWINDOW_H
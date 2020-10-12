#ifndef TCONTROLLER_H
#define TCONTROLLER_H

#include <QObject>
#include <memory>
#include "tzipviewermodel.h"
#include "mainwindow.h"

class TController : public QObject
{
    Q_OBJECT
public:
    explicit TController(QObject *parent = nullptr);
    void go();
private:
    std::unique_ptr<TZipViewerModel> _zipViewer;
    std::unique_ptr<MainWindow> _zipWindow;

signals:

public slots:
    void showData();
};

#endif // TCONTROLLER_H

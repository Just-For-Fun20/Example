#include "tcontroller.h"

TController::TController(QObject *parent) : QObject(parent)
{
    _zipViewer = std::make_unique<TZipViewerModel>();
    _zipWindow = std::make_unique<MainWindow>();
    QObject::connect(_zipWindow.get(),SIGNAL(startButtonPress()),this,SLOT(showData()));

}

void TController::go()
{
    _zipWindow->show();
}

void TController::showData()
{
    _zipViewer->setZipFileName(_zipWindow->getFileName());
    _zipViewer->openZipFile();
    auto data = _zipViewer->GetFilesNameAndSize();
    _zipWindow->tableViewInit(data);
}

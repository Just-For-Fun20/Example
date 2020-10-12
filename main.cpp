#include "tcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TController controller;
    controller.go();

    return a.exec();
}

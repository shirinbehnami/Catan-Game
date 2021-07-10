#include "ground.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ground w;
    //w.resize(900,800);
    w.showMaximized();
    return a.exec();
}

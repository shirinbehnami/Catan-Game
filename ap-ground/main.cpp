#include "ground.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ground w;
    w.resize(750,750);
    w.show();
    return a.exec();
}

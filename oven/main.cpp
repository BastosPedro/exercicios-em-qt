#include <QCoreApplication>
#include "oven.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    oven * microondas = new oven();

    return a.exec();
}

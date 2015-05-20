#include <QCoreApplication>
#include "controlador.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    controlador *acapulco = new controlador();

    return a.exec();
}

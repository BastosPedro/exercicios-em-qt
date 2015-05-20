#include <QCoreApplication>
#include "controlador.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Controlador *montezuma = new Controlador(&a);
    montezuma->plasticReady(true);
    return a.exec();
}

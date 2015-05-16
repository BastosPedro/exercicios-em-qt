#include <QDebug>
#include "queue.h"

int main() {
    queue <double> * fila1 = new queue<double>();
    fila1->enqueue(1);
    fila1->enqueue(2);
    fila1->enqueue(3);
    qDebug() << "Valor do primeiro:" << fila1->frontValue();
    qDebug() << "Comprimento da fila:" << fila1->length();
    fila1->dequeue();
    qDebug() << "Valor do primeiro:" << fila1->frontValue();
    qDebug() << "Comprimento da fila:" << fila1->length();
    fila1->~queue();
    qDebug() << "Comprimento da fila:" << fila1->length();

    return 0;
}

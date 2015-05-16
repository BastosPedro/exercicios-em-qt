#include <QCoreApplication>
#include <QDebug>
#include "stack.h"

int main()
{
    stack<double> *p2 = new stack<double>();
    p2->push(0);
    p2->push(1);
    p2->push(2);
    qDebug() << "Altura da lista" << p2->length();
    qDebug() << "topo da lista" << p2->topValue();
    p2->pop();
    qDebug() << "Altura da lista" << p2->length();
    qDebug() << "topo da lista" << p2->topValue();
    p2->clear();

    return 0;
}

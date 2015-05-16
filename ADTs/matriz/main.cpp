#include <QDebug>

#include "matriz.hpp"

int main()
{
    MatrizADT *m1 = new Matriz(3,3);
    double teste[3] = {1, 2, 3};
    m1->addColumn(teste);
    m1->addRow(teste);
    m1->addRow(teste);
    qDebug() << "Tudo certo\n";
    m1 -> insert(1, 1, 5);
    double *coluna = m1->getColumn(0);
    double *linha = m1->getRow(1);
    qDebug() << "getColumn(0):\n" << coluna[0];
    qDebug() << coluna[1];
    qDebug() << coluna[2]<<"\n";
    qDebug() << "getRow(1):\n" << linha[0];
    qDebug() << linha[1];
    qDebug() << linha[2];
    qDebug() << "matriz esta vazia? :" << QString::number(m1->isEmpty());
    qDebug() << m1->toString();
    qDebug() << m1->isDivisible();
    qDebug() << qPrintable(QString::number(m1->determinant()));
    qDebug() << qPrintable(m1->transposed()->toString());
    qDebug() << qPrintable(m1->multiply(5)->toString());
    return 0;
}

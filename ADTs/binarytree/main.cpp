#include <QCoreApplication>
#include <QDebug>
#include "tree.h"

int main() {

    tree <double> * arvore = new tree<double>();
    arvore->add(1);
    arvore->add(2);
    arvore->add(3);
    arvore->add(4);
    arvore->add(5);
    arvore->add(6);
     qDebug() << "Tamanho da arvore:" << arvore->height();
     qDebug() << "Quantidade de nos:" << arvore->countNode();
     qDebug() << "Valor da posição atual:" << arvore->getHere();
     qDebug() << "Quantidade de folhas:" << arvore->countLeaf();
     qDebug() << "Maior valor contido na arvore:" << arvore->greater();
     qDebug() << "Menor valor contido na arvore:" << arvore->lower();
}

#include <QCoreApplication>
#include "node.h"
#include "list.h"

int main()
{
    List <double> *list1 = new List<double>();
    list1->append(4);
    qDebug() << "Tamanho da lista" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    list1->append(4);
    list1->append(4);
    qDebug() << "Tamanho da lista" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    list1->append(4);
    qDebug() << "Tamanho da lista" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    qDebug() << "Valor" << list1->getValue();
    list1->clear();
    qDebug() << "Tamanho da lista" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    qDebug() << "Valor" << list1->getValue();
//#######################################################################
    list1->moveToStart();
    qDebug() << "Teste Move to Start" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    list1->moveToEnd();
    qDebug() << "Teste move to end" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    list1->prev();
    qDebug() << "Teste prev" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    list1->moveToEnd();
    qDebug() << "Teste move to end" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    list1->append(0);
    list1->append(8);
    list1->append(12);
    list1->append(14);
    list1->insert(2.5);
    list1->next();
    qDebug() << "Teste next" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    qDebug() << "Tamanho da lista" << endl << list1->length();
    qDebug() << "position" << list1->currPos();
    list1->moveToPos(1);
    qDebug() << "Teste move to position" << endl << list1->length();
    qDebug() << "position" << list1->currPos();

    list1->clear();
    qDebug() << "position" << list1->currPos();

    return 0;
}

#include <QDebug>
#include "heapmin.h"
#include "heapmax.h"

int main() {
    maxheap<double> *heap1 = new maxheap<double>();
    //minheap<double> *heap1 = new minheap<double>();
    qDebug() << "Adicionando elementos na heap:";
    for(int i = 1; i <= 5; ++i) {
        heap1->insert(2*i);
    }
    qDebug() << "Imprimindo elementos da Heap:";
    heap1->printHeap();
    qDebug() << "Testando bubble:";
    heap1->bubble(5);
    qDebug() << "Imprimindo elementos da Heap:";
    heap1->printHeap();
    qDebug() << "Testando heapfy:";
    heap1->heapfy(2);
    qDebug() << "Imprimindo elementos da Heap:";
    heap1->printHeap();
    qDebug() << "Testando buildHeap:";
    heap1->buildHeap();
    qDebug() << "Imprimindo elementos da Heap:";
    heap1->printHeap();
    return 0;
}

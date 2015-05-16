#include "sort.h"

int main()
{
    Sort <double> * sortqualquer = new Sort<double>();
    double array[] = {3,4,1,5,9,2,6,7,8};
    int size = 9;
    qDebug() << "testando array";
    sortqualquer ->arraytest(array, size);
    qDebug() << "rodando bubble sort";
    sortqualquer ->bubbleSort(array, size);
    //qDebug() << "rodando insertion sort";
    //sortqualquer ->insSort(array, size);
    //qDebug() << "rodando selection sort";
    //sortqualquer ->selSort(array, size);
    //qDebug() << "rodando shell sort";
    //sortqualquer ->shellSort(array, size);
    //qDebug() << "rodando merge sort";
    //sortqualquer ->mergeSort(array, size);
    qDebug() << "teste pos ordenamento";
    sortqualquer ->arraytest(array, size);
    return 0;
}

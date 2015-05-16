#ifndef SORTADT_H
#define SORTADT_H


template<class T> class SortADT{
public:
    virtual T* bubbleSort(T* array,int size) = 0;
    virtual T* insSort(T* array,int size) = 0;
    virtual T* selSort(T* array,int size) = 0;
    virtual T* mergeSort(T* array,int size) = 0;
    virtual T* shellSort(T* array,int size) = 0;
};

#endif // SORTADT_H

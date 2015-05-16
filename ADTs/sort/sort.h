#ifndef SORT_H
#define SORT_H
#include<QDebug>
#include "sortadt.h"

template<class T>
class Sort : public SortADT<T>{

 public:

    void arraytest(T* array,int size){
        for(int count = 0; count < size; count++){
            qDebug() << array[count];
        }
    }

    Sort(){

    }
    ~Sort(){

     }
    T* bubbleSort(T* array,int size){
          for(int countX = 0; countX<size-1; countX++){
              for(int countY = size-1; countY>countX; countY--){
                  if (array[countY] < array[countY-1]){
                      T aux = array[countY];
                      array[countY] = array[countY-1];
                      array[countY-1] = aux;
                  }
              }
          }
          return array;
    }
    T* insSort(T* array,int size){
         int countX, countY, aux;
         for(countX = 1; countX < size; countX++){
             aux = array[countX];
             countY = countX - 1;
             while(countY >=0 && array[countY] > aux){
                 array[countY+1] = array[countY];
                 countY--;
             }
             array[countY+1] = aux;
         }
        return array;
    }
    T* selSort(T* array,int size){
        int countX, countY, indexref;
        T aux;
        for(countX = 0; countX < (size-1); countX++){
            indexref = countX;
            for(countY = (countX+1); countY < size; countY++){
                if(array[countY] < array[indexref]){
                    indexref = countY;
                }
            }
            if(countX != indexref){
                aux = array[countX];
                array[countX] = array[indexref];
                array[indexref] = aux;
            }
        }
        return array;
    }
    T* mergeSort(T* array,int size){
        int mid;
        if(size > 1){
            mid = size/2;
            mergeSort(array, mid);
            mergeSort(array + mid, size-mid);
            merge(array, size);
        }
        return array;
    }
    T* shellSort(T* array,int size){
        int count, auxsize=size;
        bool flag = 1;
        T aux;
        while(flag || (auxsize > 1)){
            flag = 0;
            auxsize = (auxsize+1)/2;
            for(count = 0; count < (size - auxsize); count++){
                if(array[count + auxsize] < array[count]){
                    aux = array[count+auxsize];
                    array[count+auxsize] = array[count];
                    array[count] = aux;
                    flag = 1;
                }
            }
        }
        return array;
}
    //metódo auxiliar do mergeSort
    void merge(T* array, int size){
        int mid, countX, countY, countZ;
        T* aux;
        aux = (T*) malloc(size * sizeof(T));
        if(aux == NULL) exit(1);
        mid = size/2;
        countX = countZ = 0;
        countY = mid;
        while(countX < mid && countY < size) {
            if (array[countX] <= array[countY]){
                aux[countZ] = array[countX++];
            }
            else aux[countZ] = array[countY++];
            countZ++;
        }
        if(countX == mid){
            while(countY < size){
                aux[countZ++] = array[countY++];
            }
         }
        else {
            while(countX < mid){
                aux[countZ++] = array[countX++];
              }
           }
        for(countX = 0; countX < size; countX++){
            array[countX] = aux[countX];
        }
        free(aux);
    }

};


#endif // SORT_H


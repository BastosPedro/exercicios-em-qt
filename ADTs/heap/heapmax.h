#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <math.h>
#include "heapadt.h"


template <class E>
class maxheap : public HeapADT<E> {
    int insertCount, reallocCount;
    E *nodes;
    E *moreNodes;

public:
    maxheap() {
        zerar();
    }

    ~maxheap() {
        for(int cont = insertCount; 1 <= cont; cont--){
            remove(nodes[cont]);
        }
        free (nodes);
        zerar();
    }

    void heapfy(int pos) {
        Q_ASSERT_X(insertCount,"maxheap::heapfy","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"maxheap::heapfy","Invalid position");
        while(!(isLeaf(pos)) && ((nodes[pos] < nodes[2*pos]) || nodes[pos] < nodes[2*pos+1])){
            E aux;
            int biggest;
            if(insertCount < 2*pos+1) {
                if(nodes[2*pos] > nodes[pos]) {
                    aux = nodes[2*pos];
                    nodes[2*pos] = nodes[pos];
                    nodes[pos] = aux;
                }
            }
            else {
                if(nodes[2*pos+1] > nodes[2*pos]) {
                    biggest = 2*pos+1;
                }
                else {
                    biggest = 2*pos;
                } if(nodes[biggest] > nodes[pos]) {
                    aux = nodes[pos];
                    nodes[pos] = nodes[biggest];
                    nodes[biggest] = aux;
                }
                pos = biggest;
            }
        }
    }
    void bubble(int pos) {
        Q_ASSERT_X(insertCount,"maxheap::bubble","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"maxheap::bubble","Invalid position");
        E aux;
        while((pos != 1) && (nodes[pos/2] < nodes[pos])) {
            aux = nodes[pos/2];
            nodes[pos/2] = nodes[pos];
            nodes[pos] = aux;
            pos = pos/2;
        }
    }

    int size() const {
        int aux = 0, height =0;
        while(aux < insertCount) {
           aux += pow(2,height);
           ++height;
            }
         return height;
    }

    bool isLeaf(int pos) const {
        Q_ASSERT_X(insertCount,"maxheap::isLeaf","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"maxheap::isLeaf","Invalid position");
        return (pos>insertCount/2);
    }

    int leftchild(int pos) const {
        Q_ASSERT_X(insertCount,"maxheap::leftchild","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"maxheap::leftchild","Invalid position");
        return (2*pos);
    }

    int rightchild(int pos) const {
        Q_ASSERT_X(insertCount,"maxheap::rightchild","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"maxheap::rightchild","Invalid position");
        return (2*pos+1);
    }

    int parent(int pos) const {
        Q_ASSERT_X(insertCount,"maxheap::parent","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"maxheap::parent","Invalid position");
        return (pos/2);
    }

    void buildHeap() {
        Q_ASSERT_X(insertCount,"minheap::buildHeap","There are no nodes");
        for(int cont = insertCount/2; 1 <= cont ; cont--){
            if(!(isLeaf(cont)) && ((nodes[cont] < nodes[2*cont]) || nodes[cont] < nodes[2*cont+1])) {
                heapfy(cont);
                cont++;
            }
        }
    }

    void insert(const E& it) {
        if(!(insertCount%10)) {
            ++reallocCount;
            moreNodes = (E*) realloc (nodes, reallocCount * 10 * sizeof(E)+1);
        }
        ++insertCount;
        if (moreNodes != NULL) {
            nodes = moreNodes;
            nodes[insertCount] = it;
        } else {
            free (nodes);
            qDebug() << "Error reallocating memory";
            exit (1);
        }
        bubble(insertCount);
    }

    E get(int pos) const {
        Q_ASSERT_X(insertCount,"maxheap::get","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"maxheap::get","Invalid position");
        return nodes[pos];
    }

    void remove(const E& it) {
        Q_ASSERT_X(insertCount,"maxheap::remove","There are no nodes");
        int cont, deleted = 0;
        for(cont = 1; cont <= insertCount; cont++){
            if(nodes[cont] == it){
                nodes[cont] = nodes[insertCount];
                nodes[insertCount] = 0;
                insertCount--;
                deleted++;
                break;
            }
        }
        if(!(insertCount%10)) {
            reallocCount--;
            moreNodes = (E*) realloc (nodes, reallocCount * 10 * sizeof(E)+1);
        }
        if(!deleted) {
            qDebug() << "In maxheap::remove. The heap doesn't contain this value";
        }
        buildHeap();
    }

    void printHeap() {
        if(insertCount) {
            for(int cont = 1; cont <= insertCount; cont++){
                qDebug() << nodes[cont];
            }
        } else {
            qDebug() << "There are no nodes to print.";
        }
    }
    void zerar() {
        reallocCount = insertCount = 0;
        nodes = moreNodes = NULL;
    }
    QString toString() {
        return 0;
    }
};

#endif // MAXHEAP


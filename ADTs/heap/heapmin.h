#ifndef HEAPMIN_H
#define HEAPMIN_H
#include<math.h>
#include "heapadt.h"

template <class E>
class minheap : public HeapADT<E> {
    int insertCount, reallocCount;
    E *nodes;
    E *moreNodes;

public:
    minheap() {
        zerar();
    }

    ~minheap() {
        for(int cont = insertCount; 1 <= cont; cont--){
            remove(nodes[cont]);
        }
        free (nodes);
        zerar();
    }

    void heapfy(int pos) {
        Q_ASSERT_X(insertCount,"minheap::heapfy","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"minheap::heapfy","Invalid position");
        while(!(isLeaf(pos)) && ((nodes[pos] > nodes[2*pos]) || nodes[pos] > nodes[2*pos+1])){
            E aux;
            int smallest;
            if(insertCount < 2*pos+1) {
                if(nodes[2*pos] < nodes[pos]) {
                    aux = nodes[2*pos];
                    nodes[2*pos] = nodes[pos];
                    nodes[pos] = aux;
                }
            } else {
                if(nodes[2*pos+1] < nodes[2*pos]) {
                    smallest = 2*pos+1;
                } else {
                    smallest = 2*pos;
                } if(nodes[smallest] < nodes[pos]) {
                    aux = nodes[pos];
                    nodes[pos] = nodes[smallest];
                    nodes[smallest] = aux;
                }
                pos = smallest;
            }
        }
    }
    void bubble(int pos) {
        Q_ASSERT_X(insertCount,"minheap::bubble","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"minheap::bubble","Invalid position");
        E aux;
        while((pos != 1) && (nodes[pos] < nodes[pos/2])) {
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
        Q_ASSERT_X(insertCount,"minheap::isLeaf","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"minheap::isLeaf","Invalid position");
        return (pos>insertCount/2);
    }

    int leftchild(int pos) const {
        Q_ASSERT_X(insertCount,"minheap::leftchild","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"minheap::leftchild","Invalid position");
        return (2*pos);
    }

    int rightchild(int pos) const {
        Q_ASSERT_X(insertCount,"minheap::rightchild","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"minheap::rightchild","Invalid position");
        return (2*pos+1);
    }

    int parent(int pos) const {
        Q_ASSERT_X(insertCount,"minheap::parent","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"minheap::parent","Invalid position");
        return (pos/2);
    }

    void buildHeap() {
        Q_ASSERT_X(insertCount,"minheap::buildHeap","There are no nodes");
        for(int cont = insertCount/2; 1 <= cont ; cont--){
            if(!(isLeaf(cont)) && ((nodes[cont] > nodes[2*cont]) || nodes[cont] > nodes[2*cont+1])) {
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
        Q_ASSERT_X(insertCount,"minheap::get","There are no nodes");
        Q_ASSERT_X ((1 <= pos) && (pos <= insertCount),"minheap::get","Invalid position");
        return nodes[pos];
    }

    void remove(const E& it) {
        Q_ASSERT_X(insertCount,"minheap::remove","There are no nodes");
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
            qDebug() << "In minheap::remove. The heap doesn't contain this value";
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

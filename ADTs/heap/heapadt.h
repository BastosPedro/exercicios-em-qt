#ifndef HEAPADT_H
#define HEAPADT_H


#include <QString>
// Heap class
template <typename E> class HeapADT{
//Q_OBJECT  // q_object foi comentado porque dava erro "template classes not supported by Q_OBJECT"

private:
// Helper function to put element in its correct place
public:
virtual void heapfy(int pos)  = 0;
virtual void bubble(int pos) = 0;
virtual int size() const = 0;//retorna tamanho da heap
virtual bool isLeaf(int pos) const = 0; //retorna buff se pos é folha
virtual int leftchild(int pos) const = 0;// retorna posição do filho à esquerda
virtual int rightchild(int pos) const = 0;//retorna posição do filho à direita
virtual int parent(int pos) const  = 0;// retorna posição do pai
virtual void buildHeap()  = 0; // Constroi a heap de acordo com suas configurações
// Insert "it" into the heap
virtual void insert(const E& it) = 0;
//retorna valor na seguinte pos
virtual E get(int pos) const = 0;
//remove valor em questão
virtual void remove(const E& it) =  0;
//imprimir no formato arvore
virtual QString toString() = 0;
};

#endif // HEAPADT_H

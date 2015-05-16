#ifndef STACK_H
#define STACK_H
#include "stackadt.h"
#include "node.h"
#include <QDebug>

template <typename E>
class stack : public Stack<E> {
        Node<E> * tail;
        Node<E> * head;
        int stackLength;

public:

  stack(){
        zerar();
  }
  ~stack(){
    clear();
  }

 void clear() {
     Q_ASSERT_X(stackLength != 0, "Pilha:topValue", "Stack is already empty");
     while (stackLength != 0){
         pop();
     }
     zerar();
     qDebug() << "Stack is empty now";
    }

 void push(const E& it) {
     Node<E> * node = new Node<E> (it);
     if (!stackLength){
         head = node;
         tail = node;
     }
     else{
         node->next = head;
         head = node;
     }
    stackLength++;

    }

 E pop() {
    Q_ASSERT_X (stackLength != 0, "Pilha::pop", "Stack is empty");
     Node<E> *aux = head;
     E value = head->content;
     head = head->next;
     stackLength--;
     delete aux;
     return value;
    }

const E& topValue() const{
      Q_ASSERT_X (stackLength != 0, "Pilha:topValue", "Stack is empty");
      return head->content;
    }

int length() const{
        return stackLength;
    }

void zerar(){
    tail = 0;
    head = 0;
    stackLength = 0;
}
};
#endif // STACK_H


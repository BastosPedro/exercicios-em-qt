#ifndef QUEUE
#define QUEUE
#include<QDebug>
#include"queueadt.h"
#include"node.h"

template <class E>
class queue : public QueueADT<E> {
        Node<E> * end;
        Node<E> * front;
        int queueLength;
public:

        queue(){
            zerar();
        }
        ~queue(){
            clear();
        }

        void clear() {
            Q_ASSERT_X (queueLength!= 0, "Queue::clear", "Empty Queue");
                    while(queueLength!= 0){
                        dequeue();
                    }
                    zerar();
                    qDebug() << "Queue cleared";
        }
        void enqueue(const E& it) {
            Node<E> * node = new Node<E> (it);
                  if (!queueLength) {
                      front = node;
                      end = node;
                  } else {
                      end->next = node;
                      end = node;
                  }
                 queueLength++;
        }
        E dequeue() {
            Q_ASSERT_X (queueLength!= 0, "Queue::dequeue", "Empty Queue");
                    Node<E> *temp = front;
                    E value = end->content;
                    front= front->next;
                    queueLength--;
                    delete temp;
                    return value;
        }
        const E& frontValue() const{
            Q_ASSERT_X (queueLength != 0, "Fila:frontValue", "Queue is empty");
            return front->content;
        }
        int length() const{
            return queueLength;
        }
        void zerar(){
            end = 0;
            front = 0;
            queueLength = 0;
        }

};

#endif // QUEUE


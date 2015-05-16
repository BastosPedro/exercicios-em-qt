#ifndef LIST_H
#define LIST_H
#include "ListADT.h"
#include "node.h"
#include <QDebug>

template<class E>
class List : public ListADT<E> {

public:
    int listLength;
    int curPos;
    Node<E> *head;
    Node<E> *tail;
    Node<E> *cursor;

    List(){
        listLength = 0;
        tail = 0;
        head = 0;
        cursor = head;
    }

    ~List(){
        clear();
    }

    void zerar(){
        head  = 0;
        cursor = 0;
        tail = 0;
        curPos  = 0;
    }

    void append (const E& item) {
            Node<E> * node = new Node<E> (item);
            if(!listLength){
                head = node;
                tail = node;
                curPos = 1;
                cursor = head;
            }
            else {
                tail ->next = node;
                tail = tail->next;
            }
            listLength++;
     }
  void clear(){
      Q_ASSERT_X (head != 0, "List::clear", "Empty list");
      while(head != 0){
          cursor = head;
          head = head->next;
          delete cursor;
      }
      zerar();
      qDebug() << "cleared";
  }
  E remove(){
        Q_ASSERT_X(listLength != 0, "List :: Remove", "Empty list");
        E value = cursor -> content;
        if(head == tail){
            zerar();
        }
        else if(cursor == head){
            head = head->next;
        }
        else if(cursor == tail){
            prev();
            tail = cursor;
            cursor->next = 0;
        }
        else {
            prev();
            cursor->next = cursor->next->next;
        }
        listLength--;
        return value;
  }

  void moveToStart(){
      curPos = 1;
      cursor = head;
  }

  void moveToEnd(){
      curPos = listLength;
      cursor = tail;
  }

  void prev(){
      Q_ASSERT_X (listLength!= 0, "List :: prev", "Empty list");
      Q_ASSERT_X (cursor!= head, "List :: prev", "Invalid position");
      int aux_prev = curPos-1;
      moveToStart();
      for(int count = 1; count < aux_prev; count++){
            next();
      }
  }

  void next(){
      Q_ASSERT_X (listLength!= 0, "List :: prev", "Empty list");
      Q_ASSERT_X (cursor!= tail, "List :: prev", "Invalid position");
        cursor = cursor->next;
        curPos++;
  }
    int currPos() const{
         return curPos;
    }
    int length() const{
        return listLength;
    }
  void moveToPos(int pos){
        if(curPos <= pos){
            for(int count; count < pos; count++){
               next();
            }
        }
        else{
            for(int count = curPos; count < pos; count++){
                next();
            }
        }
  }

  const E& getValue() const{
      Q_ASSERT_X (listLength != 0,  "List::getValue", "Empty list");
      return cursor->content;
  }

  void insert(const E& item){
        if(head == 0){
            append(item);
        }
        else{
            Node<E> * node = new Node<E>(item);
            if (cursor == head){
                prev();
                node-> next = head;
                head = node;
                prev();
            }
            else{
                prev();
                node->next = cursor->next;
                cursor->next = node;
                next();
            }
        }
        listLength++;
  }
};




#endif // LIST_H


#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
public:
    E content;
    Node *next;

    Node(E content) {
        this ->content = content;
        this ->next = 0;
    }

    E getContent () const{
        return this->content;
    }
    void setContent(const E &value){
        this->content = value;
    }
    Node *getNext() const{
        return this->next;
    }
    void setNext(Node *value){
        this->next = value;
    }
};

#endif // NODE_H

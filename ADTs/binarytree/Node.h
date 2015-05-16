#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
public:
    E content;
    Node * left, * right;
    bool leaf;

    Node(E content = 0) {
       this->leaf = true;
       this->content = content;
       this->left = this->right = 0;
    }
    int beornot(){
        if(this->leaf==true) return 1;
        else return 0;
    }
};

#endif // NODE_H

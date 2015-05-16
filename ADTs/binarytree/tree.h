#ifndef TREE
#define TREE
#include "treeadt.h"

template<class E>
class tree: public BinTree<E>{
    int count_nodes;
    int count_height;
    int count_levels;
    E greater_value;
    E lower_value;
    Node<E> * curr;
    Node<E> * root;
public:
    tree(){
        zerar();
        root = NULL;
    }
    tree(Node<E>&sub){
        root = new Node<E>();
        curr = root;
    }
    ~tree(){
        Q_ASSERT_X(count_nodes, "tree::~tree", "Empty Tree Already");
         clear();
    }
    void add(const E &item){
        if(curr == NULL){
                    curr = new Node<E>(item);
                    greater_value = item;
                    lower_value = item;
                }
                else{
                    analyse(item);
                    if(curr->content > item){
                        add(item,curr->right);
                    }else if (curr->content < item){
                        add(item,curr->left);
                    }
                }
                count_nodes++;
    }
   void add(const E &item, Node<E>* leaf){
            Node<E>* curr = leaf;
            if(curr == NULL){
                curr = new Node<E>(item);
            }
            else{
                if(curr->content > item){
                    add(item,curr->right);
                }else if (curr->content < item){
                    add(item,curr->left);
                }
            }

        }
    void remove(E item){

    }
    void clear(){

    }
    bool inTree(const E item){

    }
    const E lower(){
        Q_ASSERT_X (count_nodes, "tree::lower", "Empty tree");
        return lower_value;
    }

    const E greater(){
        Q_ASSERT_X (count_nodes, "tree::greater", "Empty tree");
        return greater_value;
    }
    QString toString(){

    }
    int countNode() const{
       // Q_ASSERT_X (!count_nodes, "tree::nodes", "Empty tree");
        return count_nodes;
    }
    int countLevel() const{
        return count_levels;
    }
    int countLeaf() const{
        if (root ==0) return 0;
        else if (root->beornot()==1) return 1;
        else{
            tree <E> * subtree1 = new tree<E>();
            subtree1->root = root->left;
            tree <E> * subtree2 = new tree<E>();
            subtree2->root = root->right;

            return subtree1->countLeaf() + subtree2->countLeaf();
            }
        }
    int height() const{
        return count_height;
    }
    const Node<E> *getTree(){
        return root;
    }
    void addSubTree(Node<E>*& node){

    }
    void toLeft(){
        Q_ASSERT_X (count_nodes, "tree::toLeft", "Empty tree");
        Q_ASSERT_X (curr->left, "tree::toLeft", "There are no nodes to the left");
        curr = curr->left;
    }
    void toRight(){
        Q_ASSERT_X (count_nodes, "tree::toRIght", "Empty tree");
        Q_ASSERT_X (curr->right, "tree::toRight", "There are no nodes to the right");
        curr = curr->right;
    }
    const E getHere() const{
        Q_ASSERT_X (count_nodes, "binarytree::getHere", "Empty Tree");
        return curr->content;
    }
    void zerar(){
        count_nodes = 0;
        count_height = 0;
        count_levels = 0;
        curr = 0;
        root = 0;
    }
    void analyse(const E& item) {
        if(greater_value < item) greater_value = item;
        if(item < lower_value) lower_value = item;
    }
};

#endif // TREE


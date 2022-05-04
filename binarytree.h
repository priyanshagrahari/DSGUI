#ifndef BINARYTREE_H
#define BINARYTREE_H


struct binary_node {
    binary_node *left;
    binary_node *right;
    int data;
};

binary_node* root;

class binary_tree {
public:
    binary_tree();
    ~binary_tree();

    void Insert(int data);
    binary_node* Insert2(binary_node*, binary_node*);
    void Delete(int data);
};


#endif //BINARYTREE_H

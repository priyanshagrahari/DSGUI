#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


struct node {
	int key;
	struct node *left, *right;
};

class binary_search_tree {
private:
    node *root;
    
public:
    binary_search_tree();
    ~binary_search_tree();

    node* minValueNode(node* node);
    node* insert(node* node, int key);
    node* deleteNode(node* node, int key);
};


#endif //BINARYSEARCHTREE_H

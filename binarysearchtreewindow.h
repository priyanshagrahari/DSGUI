#ifndef BINARYSEARCHTREEWINDOW_H
#define BINARYSEARCHTREEWINDOW_H

#include <QMainWindow>

struct binary_node {
    binary_node *left;
    binary_node *right;
    int data;
};

class binary_search_tree {
private:
    binary_node *root;
    
public:
    binary_search_tree();
    ~binary_search_tree();

    binary_node* Insert(binary_node* node, int data);
    binary_node* Delete(binary_node* node, int data);
    binary_node* Search(binary_node* node, int data);
};

namespace Ui {
class BinarySearchTreeWindow;
}

#endif //BINARYSEARCHTREEWINDOW_H

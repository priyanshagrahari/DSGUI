#ifndef BINARYTREEWINDOW_H
#define BINARYTREEWINDOW_H

#include <QMainWindow>

struct binary_node {
    binary_node *left;
    binary_node *right;
    int data;
};

class binary_tree {
private:
    binary_node *root;

public:
    binary_tree();
    ~binary_tree();

    binary_node* Insert(binary_node* node, int data);
    binary_node* Delete(binary_node* node, int data);
};

namespace Ui {
class BinaryTreeWindow;
}

#endif //BINARYTREEWINDOW_H

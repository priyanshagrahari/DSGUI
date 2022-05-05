#include <iostream>
#include "binarytree.h"

binary_tree::binary_tree() {
    root = nullptr;
}

binary_node* binary_tree::Insert2(binary_node* temp, binary_node* newnode)
{
    if (temp == nullptr) {
        temp = newnode;
    }
    else if (temp->data < newnode->data) {
        Insert2(temp->right, newnode);
        if (temp->right == nullptr)
            temp->right = newnode;
    }
    else {
        Insert2(temp->left, newnode);
        if (temp->left == nullptr)
            temp->left = newnode;
    }
    return temp;
}

void binary_tree::Insert(int data) {
    binary_node* temp = root, *newnode;
    newnode = new binary_node;
    newnode->left = nullptr;
    newnode->right = nullptr;
    newnode->data = data;
    root = Insert2(temp, newnode);
}

void binary_tree::Delete(int key)
{
    binary_node *temp = root, *parent = root, *marker;
    if (temp == nullptr)
        std::cout << "The tree is empty" << std::endl;
    else {
        while (temp != nullptr && temp->data != key) {
            parent = temp;
            if (temp->data < key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
    }
    marker = temp;
    if (temp == NULL)
        std::cout << "No node present";
    else if (temp == root) {
        if (temp->right == NULL && temp->left == NULL) {
            root = NULL;
        }
        else if (temp->left == NULL) {
            root = temp->right;
        }
        else if (temp->right == NULL) {
            root = temp->left;
        }
        else {
            binary_node* temp1;
            temp1 = temp->right;
            while (temp1->left != NULL) {
                temp = temp1;
                temp1 = temp1->left;
            }
            if (temp1 != temp->right) {
                temp->left = temp1->right;
                temp1->right = root->right;
            }
            temp1->left = root->left;
            root = temp1;
        }
    }
    else {
        if (temp->right == NULL && temp->left == NULL) {
            if (parent->right == temp)
                parent->right = NULL;
            else
                parent->left = NULL;
        }
        else if (temp->left == NULL) {
            if (parent->right == temp)
                parent->right = temp->right;
            else
                parent->left = temp->right;
        }
        else if (temp->right == NULL) {
            if (parent->right == temp)
                parent->right = temp->left;
            else
                parent->left = temp->left;
        }
        else {
            binary_node* temp1;
            parent = temp;
            temp1 = temp->right;
            while (temp1->left != NULL) {
                parent = temp1;
                temp1 = temp1->left;
            }
            if (temp1 != temp->right) {
                temp->left = temp1->right;
                temp1->right = parent->right;
            }
            temp1->left = parent->left;
            parent = temp1;
        }
    }
    delete marker;
}

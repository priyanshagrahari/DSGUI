#include "node.h"

Node::Node()
{
    next = nullptr;
}

Node::Node(int v) {
    this->v = v;
    next = nullptr;
}

Node::Node(int v, Node *n) {
    this->v = v;
    next = n;
}

Node* Node::get_n() {
    return next;
}

int Node::get_v() {
    return v;
}

void Node::set_n(Node *n) {
    next = n;
}

void Node::set_v(int v) {
    this->v = v;
}

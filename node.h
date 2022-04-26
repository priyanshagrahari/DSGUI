#ifndef NODE_H
#define NODE_H


class Node
{
private:
    int v;
    Node *next;

public:
    Node();
    Node(int v);
    Node(int v, Node *n);

    void set_v(int v);
    void set_n(Node *n);

    int get_v();
    Node *get_n();
};

#endif // NODE_H

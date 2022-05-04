#ifndef STACKWINDOW_H
#define STACKWINDOW_H

#include "node.h"
#include <QMainWindow>

namespace Ui {
class StackWindow;
}

class Stack {
    Node *top;

public:
    Stack();
    ~Stack();

    Node *Push(int v);
    int Pop();
    Node *get_top();
};

class StackWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StackWindow(QWidget *parent = nullptr);
    ~StackWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_ll_pbut_clicked();

    void about_clicked();

private:
    Ui::StackWindow *ui;
    Stack *s;
    void populate();
};

#endif // STACKWINDOW_H

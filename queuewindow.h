#ifndef QUEUEWINDOW_H
#define QUEUEWINDOW_H

#include <QMainWindow>
#include "node.h"

namespace Ui {
class QueueWindow;
}

class Queue {
    Node *front, *back;

public:
    Queue();
    ~Queue();

    Node *get_front();
    Node *Enqueue(int);
    int Dequeue();
};

class QueueWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QueueWindow(QWidget *parent = nullptr);
    ~QueueWindow();

private slots:
    void on_ll_pbut_clicked();

    void about_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_2_clicked();

private:
    Ui::QueueWindow *ui;
    Queue *q;
    void populate();
};

#endif // QUEUEWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arraywindow.h"
#include "binarysearchtreewindow.h"
#include "binarytreewindow.h"
#include "linkedlistwindow.h"
#include "queuewindow.h"
#include "stackwindow.h"
#include "hashtablewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ArrayWindow *arr_win;
    LinkedListWindow *ll_win;
    StackWindow *stk_win;
    QueueWindow *q_win;
    HashTableWindow *ht_win;
    BinaryTreeWindow *bt_win;
    BinarySearchTreeWindow *bst_win;

private slots:
    void on_array_pbut_clicked();
    void on_ll_pbut_clicked();
    void on_stack_pbut_clicked();

    void q_clicked();
    void bt_clicked();
    void bst_clicked();
    void h_clicked();
    void ht_clicked();
    void about_clicked();

private:
    Ui::MainWindow *ui;

    int active_ds;
    enum ds {
        array,
        ll,
        stack,
        queue,
        btree,
        bstree,
        heap,
        htable
    } dstructs;
};

#endif // MAINWINDOW_H

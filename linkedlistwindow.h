#ifndef LINKEDLISTWINDOW_H
#define LINKEDLISTWINDOW_H

#include <QMainWindow>
#include "node.h"
#include "qtreewidget.h"

class ll_ {
private:
    Node *head;

public:
    ll_();
    ~ll_();
    Node *get_head();

    Node *Insert_1(int v);
    Node *Insert_2(int v, Node *after);
    void Delete(Node *me);
};

namespace Ui {
class LinkedListWindow;
}

class LinkedListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LinkedListWindow(QWidget *parent = nullptr);
    ~LinkedListWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_treeWidget_itemSelectionChanged();

    void on_pushButton_clicked();

    void on_checkBox_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_ll_pbut_clicked();

    void about_clicked();

private:
    Ui::LinkedListWindow *ui;
    ll_ *llist;
    std::map<QTreeWidgetItem*, Node*> mm;
    QTreeWidgetItem *sel;
    void populate();
};

#endif // LINKEDLISTWINDOW_H

#include "linkedlistwindow.h"
#include "ui_linkedlistwindow.h"
#include <algorithm>
#include <windows.h>
#include <iostream>

LinkedListWindow::LinkedListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LinkedListWindow)
{
    ui->setupUi(this);

    QPushButton *q = new QPushButton("Queue");
    q->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(q);
    //connect(q, SIGNAL(clicked()), SLOT(q_clicked()));

    QPushButton *bt = new QPushButton("Binary Tree");
    bt->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(bt);

    QPushButton *bst = new QPushButton("Binary Search Tree");
    bst->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(bst);

    QPushButton *h = new QPushButton("Heap");
    h->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(h);

    QPushButton *ht = new QPushButton("Hash Table");
    ht->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(ht);

    // ll exclusive
    ui->ll_pbut->setDisabled(true);
    llist = new ll_();
    ui->lineEdit->setValidator(new QIntValidator(INT_MIN, INT_MAX, this));
}

LinkedListWindow::~LinkedListWindow()
{
    delete ui;
}

// ll exclusive

ll_::ll_() {
    head = nullptr;
}

Node *ll_::get_head() {
    return head;
}

Node *ll_::Insert_1(int v) {
    Node *nn = new Node(v);
    if (head == nullptr) {
        head = nn;
        return nn;
    }
    Node *t = head;
    while (t->get_n() != nullptr) {
        t = t->get_n();
    }
    t->set_n(nn);
    return nn;
}

Node *ll_::Insert_2(int v, Node *after) {
    Node *nn = new Node(v);
    nn->set_n(after->get_n());
    after->set_n(nn);
    return nn;
}

void ll_::Delete(Node *me) {
    if (me == head) {
        head = me->get_n();
        delete me;
        return;
    }
    Node *t = head;
    while (t->get_n() != me) {
        t = t->get_n();
    }
    t->set_n(me->get_n());
    delete me;
    return;
}

void LinkedListWindow::populate () {
    ui->treeWidget->clear();
    mm.clear();
    Node *t = llist->get_head();
    while (t != nullptr) {
        QTreeWidgetItem *li = new QTreeWidgetItem(ui->treeWidget);
        li->setText(0, QString::number(t->get_v()));
        li->setText(1, QString::number((long long)t));
        mm[li] = t;
        ui->treeWidget->addTopLevelItem(li);
        t = t->get_n();
    }
    if (sel != NULL) {
        ui->treeWidget->clearSelection();
        sel = NULL;
    }
    return;
}

void LinkedListWindow::on_pushButton_4_clicked()
{
    // insert clicked
    int val = ui->lineEdit->text().toInt();
    if (llist->get_head() == nullptr
            || ui->checkBox->isChecked()
            || sel == NULL) {
        llist->Insert_1(val);
        // std::cout << "insert 1\n";
    } else {
        if (mm[sel] == NULL) {
            // std::cout << "fix the map\n";
            return;
        }
        llist->Insert_2(val, mm[sel]);
        // std::cout << "insert 2\n";
        sel = NULL;
    }
    populate();
    return;
}


void LinkedListWindow::on_treeWidget_itemSelectionChanged()
{
    auto sel_list = ui->treeWidget->selectedItems();
    if (!sel_list.empty()) {
        sel = sel_list.back();
        ui->label_3->setText(sel->text(0));
        ui->label_4->setText(sel->text(0));
    }
    return;
}


void LinkedListWindow::on_pushButton_clicked()
{
    ui->treeWidget->clearSelection();
    sel = NULL;
    ui->label_3->setText("Selected Element");
    ui->label_4->setText("Selected Element");
    return;
}


void LinkedListWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()) {
        on_pushButton_clicked();
    }
    return;
}


void LinkedListWindow::on_pushButton_2_clicked()
{
    on_pushButton_clicked();
}


void LinkedListWindow::on_pushButton_3_clicked()
{
    // delete clicked
    if (mm[sel] == NULL) {
        // std::cout << "fix the map\n";
        return;
    }
    llist->Delete(mm[sel]);
    on_pushButton_clicked();
    populate();
    return;
}


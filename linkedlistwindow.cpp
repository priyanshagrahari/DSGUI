#include "linkedlistwindow.h"
#include "ui_linkedlistwindow.h"

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
}

LinkedListWindow::~LinkedListWindow()
{
    delete ui;
}

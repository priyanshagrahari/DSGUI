#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arraywindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    active_ds = -1;

    QPushButton *q = new QPushButton("Queue");
    q->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(q);
    connect(q, SIGNAL(clicked()), SLOT(q_clicked()));

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

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_array_pbut_clicked()
{
    this->hide();
    if(this->isMaximized()) arr_win.showMaximized();
    else arr_win.show();
}


void MainWindow::on_ll_pbut_clicked()
{
    this->hide();
    if(this->isMaximized()) ll_win.showMaximized();
    else ll_win.show();
}


void MainWindow::on_stack_pbut_clicked()
{
    ui->welcome->setText("Stack selected...");
    ui->begin->setVisible(false);
}

void MainWindow::q_clicked() {
    ui->welcome->setText("Queue selected...");
    ui->begin->setVisible(false);
}

// common part ends

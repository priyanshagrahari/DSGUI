#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include <iostream>

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
    connect(bt, SIGNAL(clicked()), SLOT(bt_clicked()));

    QPushButton *bst = new QPushButton("Binary Search Tree");
    bst->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(bst);
    connect(bst, SIGNAL(clicked()), SLOT(bst_clicked()));

    QPushButton *h = new QPushButton("Heap");
    h->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(h);
    connect(h, SIGNAL(clicked()), SLOT(h_clicked()));

    QPushButton *ht = new QPushButton("Hash Table");
    ht->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    ui->buttonList->addWidget(ht);
    connect(ht, SIGNAL(clicked()), SLOT(ht_clicked()));

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);
    connect(about, SIGNAL(clicked()), SLOT(about_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_array_pbut_clicked()
{
    arr_win = new ArrayWindow(this);
    this->hide();
    if(this->isMaximized()) arr_win->showMaximized();
    else arr_win->show();
}


void MainWindow::on_ll_pbut_clicked()
{
    ll_win = new LinkedListWindow(this);
    this->hide();
    if(this->isMaximized()) ll_win->showMaximized();
    else ll_win->show();
}


void MainWindow::on_stack_pbut_clicked()
{
    stk_win = new StackWindow(this);
    this->hide();
    if(this->isMaximized()) stk_win->showMaximized();
    else stk_win->show();
}

void MainWindow::q_clicked() {
    q_win = new QueueWindow(this);
    this->hide();
    if(this->isMaximized()) q_win->showMaximized();
    else q_win->show();
}

void MainWindow::bt_clicked() {
    std::cout << "bt clicked\n";
}

void MainWindow::bst_clicked() {
    std::cout << "bst clicked\n";
}

void MainWindow::h_clicked() {}

void MainWindow::ht_clicked() {
    ht_win = new HashTableWindow(this);
    this->hide();
    if(this->isMaximized()) q_win->showMaximized();
    else q_win->show();
}

void MainWindow::about_clicked() {
    AboutWindow aw(this);
    aw.setModal(true);
    aw.exec();
}


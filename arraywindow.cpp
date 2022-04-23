#include "arraywindow.h"
#include "ui_arraywindow.h"
#include <iostream>

ArrayWindow::ArrayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArrayWindow)
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

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);

    // array exculsive
    ui->array_pbut->setDisabled(true);

    arr = nullptr;
    size = 1;
    ui->sizereset->setDisabled(true);
    ui->index->setDisabled(true);
    ui->newvalue->setDisabled(true);
    ui->newvalue->setValidator(new QIntValidator(INT_MIN, INT_MAX, this));
}

ArrayWindow::~ArrayWindow()
{
    delete ui;
}

void ArrayWindow::on_sizeset_clicked()
{
    size = ui->sizeinp->value();
    ui->index->setValidator(new QIntValidator(0, 2000, this));
    ui->index->setToolTip("Valid index range 0 - "+QString::number(size-1));
    ui->sizeset->setDisabled(true);
    ui->sizereset->setDisabled(false);
    ui->index->setDisabled(false);
    ui->newvalue->setDisabled(false);
    arr = new int[size];
    if (ui->zero->isChecked()) {
        for (int i = 0; i < size; i ++) arr[i] = 0;
    }
    for (int i = 0; i < size; i ++) {
        QTreeWidgetItem *n = new QTreeWidgetItem(ui->treeWidget);
        n->setText(0, QString::number(i));
        n->setText(1, QString::number(arr[i]));
        ui->treeWidget->addTopLevelItem(n);
    }
}


void ArrayWindow::on_sizereset_clicked()
{
    ui->sizeset->setDisabled(false);
    ui->sizereset->setDisabled(true);
    ui->index->setDisabled(true);
    ui->newvalue->setDisabled(true);
    ui->sizeinp->setValue(1);
    ui->index->clear();
    ui->newvalue->clear();
    int h = ui->treeWidget->height();
    for (int i = 0; i < h; i ++) {
        delete ui->treeWidget->takeTopLevelItem(0);
    }
    delete arr;
}


void ArrayWindow::on_treeWidget_itemSelectionChanged()
{
    QList s = ui->treeWidget->selectedItems();
    for (int i = 0; i < s.length(); i ++) {
        ui->index->setText(s[i]->text(0));
    }
}


void ArrayWindow::on_newvalue_returnPressed()
{
    if (ui->index->text() == "") return;
    int nv = ui->newvalue->text().toInt();
    int ni = ui->index->text().toInt();
    arr[ni] = nv;
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
      if ((*it)->text(0)==ui->index->text())
        break;
      ++it;
    }
    (*it)->setText(1, ui->newvalue->text());
}


void ArrayWindow::on_index_returnPressed()
{
    int ni = ui->index->text().toInt();
    if (ni > size - 1) {
        ui->index->setText(QString::number(size - 1));
    }
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
      if ((*it)->text(0)==ui->index->text())
        break;
      ++it;
    }
    ui->treeWidget->clearSelection();
    (*it)->setSelected(true);
}


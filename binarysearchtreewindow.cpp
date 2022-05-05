#include "binarysearchtreewindow.h"
#include "aboutwindow.h"
#include "qdialog.h"
#include "qdialogbuttonbox.h"
#include "qgraphicsitem.h"
#include "ui_binarysearchtreewindow.h"
#include <iostream>
#define MAX 100000
#define LEFT(a) (2*((a) + 1) - 1)
#define RIGHT(a) (2*((a) + 1))
#define PARENT(a) (((a + 1)/2)-1)

BinarySearchTreeWindow::BinarySearchTreeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BinarySearchTreeWindow)
{
    ui->setupUi(this);

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);
    connect(about, SIGNAL(clicked()), SLOT(about_clicked()));

    // bst exclusive
    tsize = 0;
    s = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(s);
    pen = new QPen(Qt::black);
    brush = new QBrush(Qt::black);
    pen->setWidth(3);
    for (int i = 0; i < 1000000; i ++) {
        bst_values.push_back(MAX + 1);
    }
}

BinarySearchTreeWindow::~BinarySearchTreeWindow()
{
    delete ui;
}

void BinarySearchTreeWindow::on_ll_pbut_clicked()
{
    QDialog dlg(this);
    QVBoxLayout la(&dlg);
    QLabel ed;
    la.addWidget(&ed);
    ed.setText("This will take you to the start screen.\nThis binary search tree instance will be reset.");

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                       |QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), &dlg, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), &dlg, SLOT(reject()));

    la.addWidget(buttonBox);
    dlg.setLayout(&la);
    dlg.setModal(true);

    if(dlg.exec() == QDialog::Accepted)
    {
        QWidget *parent = this->parentWidget();
        if (this->isMaximized()) {
            parent->showMaximized();
        } else {
            parent->show();
        }
        this->close();
    }
    dlg.close();
}

void BinarySearchTreeWindow::about_clicked() {
    AboutWindow aw(this);
    aw.setModal(true);
    aw.exec();
}

void BinarySearchTreeWindow::drawNode(int x, int y, std::vector<int>::iterator v) {
    if (*v > MAX) return;
    QGraphicsEllipseItem *e = s->addEllipse(x-25, y-25, 50, 50, *pen, *brush);
    e->setFlag(QGraphicsItem::ItemIsSelectable);
    el[e] = v;
    QGraphicsTextItem *t = s->addText(QString::number(*v));
    t->setDefaultTextColor(Qt::white);
    t->setPos(x + 4 - 25, y + 5 - 25);
    t->setScale(2);
    return;
}

void BinarySearchTreeWindow::connectNodes(int x1, int y1, int x2, int y2) {
    s->addLine(x1, y1, x2, y2, *pen);
    return;
}

void BinarySearchTreeWindow::drawTree() {
    int h = 1 + std::floor(log2(tsize));
    int y = 0, x_i = 0;
    int d = 60;
    for (int i = h; i > 1; i --, y -= 100) {
        int x = x_i;
        int x_n = (x_i + (x_i + d)) / 2;
        for (int k = 0, j = std::pow(2, i - 1) - 1; j < tsize && j < ((int)std::pow(2, i) - 1); k ++, j ++) {
            if (bst_values[j] <= MAX) connectNodes(x, y, x_n, y - 100);
            if (k % 2) {
                x_n += 2*d;
            }
            // std::cout << x << ' ';
            x += d;
        }
        x_i = (x_i + (x_i + d)) / 2;
        d *= 2;
        // std::cout << '\n' << x << ' ' << d << '\n';
    }
    x_i = 0; d = 60; y = 0;
    for (int i = h; i >= 1; i --, y -= 100) {
        int x = x_i;
        for (int j = std::pow(2, i - 1) - 1; j < tsize && j < ((int)std::pow(2, i) - 1); j ++) {
            drawNode(x, y, bst_values.begin()+j);
            // std::cout << x << ' ';
            x += d;
        }
        x_i = (x_i + (x_i + d)) / 2;
        d *= 2;
        // std::cout << '\n' << x << ' ' << d << '\n';
    }
    return;
}

void BinarySearchTreeWindow::bst_insert(int v) {
    if (bst_values[0] > MAX) {
        bst_values[0] = v;
        tsize = 1;
    }
    else {
        for (int i = 0; i < (int)bst_values.size(); ) {
            // std::cout << i << ' ';
            if (v < bst_values[i]) {
                if (bst_values[LEFT(i)] > MAX) {
                    bst_values[LEFT(i)] = v;
                    tsize = std::max(tsize, LEFT(i) + 1);
                    return;
                } else {
                    i = LEFT(i);
                }
            }
            else if (v > bst_values[i]) {
                if (bst_values[RIGHT(i)] > MAX) {
                    bst_values[RIGHT(i)] = v;
                    tsize = std::max(tsize, RIGHT(i) + 1);
                    return;
                } else {
                    i = RIGHT(i);
                }
            }
        }
    }
    return;
}

void BinarySearchTreeWindow::move_up_l(int i_) {
    if (bst_values[LEFT(i_)] < MAX) {
        bst_values[PARENT(LEFT(i_))] = bst_values[LEFT(i_)];
        move_up_l(LEFT(i_));

    }
    if (bst_values[RIGHT(i_)] < MAX) {
        bst_values[i_] = bst_values[RIGHT(i_)];
        move_up_l(RIGHT(i_));
    }
    return;
}

void BinarySearchTreeWindow::move_up_r(int i_) {
    if (bst_values[RIGHT(i_)] < MAX) {
        bst_values[PARENT(RIGHT(i_))] = bst_values[RIGHT(i_)];
        move_up_r(RIGHT(i_));
    }
    if (bst_values[LEFT(i_)] < MAX) {
        bst_values[i_] = bst_values[LEFT(i_)];
        move_up_r(LEFT(i_));
    }
    return;
}

void BinarySearchTreeWindow::bst_delete(int i_) {
    // is leaf
    if (bst_values[LEFT(i_)] > MAX && bst_values[RIGHT(i_)] > MAX) {
        bst_values[i_] = MAX + 1;
        return;
    }
    // only one child
    else if (bst_values[LEFT(i_)] > MAX) {
        bst_values[i_] = bst_values[RIGHT(i_)];
        move_up_l(RIGHT(i_));
        return;
    }
    else if (bst_values[RIGHT(i_)] > MAX) {
        bst_values[i_] = bst_values[LEFT(i_)];
        move_up_r(LEFT(i_));
        return;
    }
    // two children
    int j_ = RIGHT(i_);
    while (bst_values[LEFT(j_)] < MAX) {
        j_ = LEFT(j_);
    }
    bst_values[i_] = bst_values[j_];
    bst_delete(j_);
    return;
}

void BinarySearchTreeWindow::on_inp_clicked()
{
    int v = ui->in->text().toInt();
    bst_insert(v);
    s->clear();
    drawTree();
    return;
}

void BinarySearchTreeWindow::on_dlp_clicked()
{
    QList l = s->selectedItems();
    if (l.size() > 0) {
        ui->dll->setText("Deleted " + QString::number(*el[(QGraphicsEllipseItem*)(l[0])]));
        auto x = el[(QGraphicsEllipseItem*)(l[0])];
        int i_ = x - bst_values.begin();
        bst_delete(i_);
        s->clear();
        drawTree();
        return;
    }
    ui->dll->setText("Select a node first!");
    return;
}


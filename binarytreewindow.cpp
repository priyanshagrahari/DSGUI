#include "binarytreewindow.h"
#include "aboutwindow.h"
#include "qdialog.h"
#include "qdialogbuttonbox.h"
#include "qlabel.h"
#include "ui_binarytreewindow.h"
#include "QGraphicsTextItem"
#include <cmath>
#include <iostream>

BinaryTreeWindow::BinaryTreeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BinaryTreeWindow)
{
    ui->setupUi(this);

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);
    connect(about, SIGNAL(clicked()), SLOT(about_clicked()));

    // bt exclusive
    s = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(s);
    pen = new QPen(Qt::black);
    brush = new QBrush(Qt::black);
    pen->setWidth(3);
}

BinaryTreeWindow::~BinaryTreeWindow()
{
    delete ui;
}

void BinaryTreeWindow::on_ll_pbut_clicked()
{
    QDialog dlg(this);
    QVBoxLayout la(&dlg);
    QLabel ed;
    la.addWidget(&ed);
    ed.setText("This will take you to the start screen.\nThis binary tree instance will be reset.");

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

void BinaryTreeWindow::about_clicked() {
    AboutWindow aw(this);
    aw.setModal(true);
    aw.exec();
}

void BinaryTreeWindow::drawNode(int x, int y, std::vector<int>::iterator v) {
    QGraphicsEllipseItem *e = s->addEllipse(x-25, y-25, 50, 50, *pen, *brush);
    e->setFlag(QGraphicsItem::ItemIsSelectable);
    el[e] = v;
    QGraphicsTextItem *t = s->addText(QString::number(*v));
    t->setDefaultTextColor(Qt::white);
    t->setPos(x + 4 - 25, y + 5 - 25);
    t->setScale(2);
    return;
}

void BinaryTreeWindow::connectNodes(int x1, int y1, int x2, int y2) {
    s->addLine(x1, y1, x2, y2, *pen);
    return;
}

void BinaryTreeWindow::drawTree() {
    int h = 1 + std::floor(log2(bt_values.size()));
    int y = 0, x_i = 0;
    int d = 60;
    for (int i = h; i > 1; i --, y -= 100) {
        int x = x_i;
        int x_n = (x_i + (x_i + d)) / 2;
        for (int k = 0, j = std::pow(2, i - 1) - 1; j < (int)bt_values.size() && j < ((int)std::pow(2, i) - 1); k ++, j ++) {
            connectNodes(x, y, x_n, y - 100);
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
        for (int j = std::pow(2, i - 1) - 1; j < (int)bt_values.size() && j < ((int)std::pow(2, i) - 1); j ++) {
            drawNode(x, y, bt_values.begin()+j);
            // std::cout << x << ' ';
            x += d;
        }
        x_i = (x_i + (x_i + d)) / 2;
        d *= 2;
        // std::cout << '\n' << x << ' ' << d << '\n';
    }
    return;
}

void BinaryTreeWindow::on_inp_clicked()
{
    int v = ui->in->text().toInt();
    bt_values.push_back(v);
    s->clear();
    drawTree();
    return;
}


void BinaryTreeWindow::on_dlp_clicked()
{
    QList l = s->selectedItems();
    if (l.size() > 0) {
        ui->dll->setText("Deleted " + QString::number(*el[(QGraphicsEllipseItem*)(l[0])]));
        *el[(QGraphicsEllipseItem*)(l[0])] = bt_values.back();
        bt_values.erase(bt_values.end() - 1);
        s->clear();
        drawTree();
        return;
    }
    ui->dll->setText("Select a node first!");
    return;
}


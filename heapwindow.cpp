#include "heapwindow.h"
#include "aboutwindow.h"
#include "qdialog.h"
#include "qdialogbuttonbox.h"
#include "qgraphicsitem.h"
#include "ui_heapwindow.h"
#include <iostream>
#define LEFT(a) (2*((a) + 1) - 1)
#define RIGHT(a) (2*((a) + 1))
#define PARENT(a) ((a + 1)/2 - 1)

HeapWindow::HeapWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HeapWindow)
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

HeapWindow::~HeapWindow()
{
    delete ui;
}

void HeapWindow::on_ll_pbut_clicked()
{
    QDialog dlg(this);
    QVBoxLayout la(&dlg);
    QLabel ed;
    la.addWidget(&ed);
    ed.setText("This will take you to the start screen.\nThis heap instance will be reset.");

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

void HeapWindow::about_clicked()
{
    AboutWindow aw(this);
    aw.setModal(true);
    aw.exec();
}

void HeapWindow::drawNode(int x, int y, std::vector<int>::iterator v) {
    QGraphicsEllipseItem *e = s->addEllipse(x-25, y-25, 50, 50, *pen, *brush);
    QGraphicsTextItem *t = s->addText(QString::number(*v));
    t->setDefaultTextColor(Qt::white);
    t->setPos(x + 4 - 25, y + 5 - 25);
    t->setScale(2);
    return;
}

void HeapWindow::connectNodes(int x1, int y1, int x2, int y2) {
    s->addLine(x1, y1, x2, y2, *pen);
    return;
}

void HeapWindow::drawTree() {
    int h = 1 + std::floor(log2(h_values.size()));
    int y = 0, x_i = 0;
    int d = 60;
    for (int i = h; i > 1; i --, y -= 100) {
        int x = x_i;
        int x_n = (x_i + (x_i + d)) / 2;
        for (int k = 0, j = std::pow(2, i - 1) - 1; j < (int)h_values.size() && j < ((int)std::pow(2, i) - 1); k ++, j ++) {
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
        for (int j = std::pow(2, i - 1) - 1; j < (int)h_values.size() && j < ((int)std::pow(2, i) - 1); j ++) {
            drawNode(x, y, h_values.begin()+j);
            // std::cout << x << ' ';
            x += d;
        }
        x_i = (x_i + (x_i + d)) / 2;
        d *= 2;
        // std::cout << '\n' << x << ' ' << d << '\n';
    }
    return;
}

void HeapWindow::heapify_(int i) {
    int min = h_values[i], who = -1;
    if (h_values[LEFT(i)] < min) {
        min = h_values[LEFT(i)];
        who = 0;
    }
    if (RIGHT(i) < (int)h_values.size() && h_values[RIGHT(i)] < min) {
        min = h_values[RIGHT(i)];
        who = 1;
    }
    if (who != -1) {
        if (who) {
            h_values[RIGHT(i)] = h_values[i];
        } else {
            h_values[LEFT(i)] = h_values[i];
        }
        h_values[i] = min;
        if (!(PARENT(i) < 0)) heapify_(PARENT(i));
        return;
    }
    return;
}

void HeapWindow::heapify() {
    int s_ = PARENT(h_values.size() - 1);
    // std::cout << s_ << '\n';
    if (s_ < 0) return;
    while (s_ >= 0) {
        heapify_(s_);
        s_ --;
    }
    return;
}

void HeapWindow::on_inp_clicked()
{
    int v = ui->in->text().toInt();
    h_values.push_back(v);
    heapify();
    s->clear();
    drawTree();
    return;
}

void HeapWindow::on_dlp_clicked()
{
    if (h_values.size() == 0) {
        ui->dll->setText("Heap empty!");
        return;
    }
    ui->dll->setText("Extracted " + QString::number(h_values[0]));
    h_values[0] = h_values.back();
    h_values.erase(h_values.end() - 1);
    heapify();
    s->clear();
    drawTree();
    return;
}


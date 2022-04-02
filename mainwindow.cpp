#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arrayknowmore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    active_ds = -1;
    ui->knowmore->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_array_pbut_clicked()
{
    // ui->welcome->setVisible(false);
    if (active_ds == -1) {
        active_ds = array;
        ui->begin->setVisible(false);
        ui->welcome->setText("Array selected...");
        ui->knowmore->setVisible(true);
    } else {
        // ask before changing
    }
}


void MainWindow::on_ll_pbut_clicked()
{
    // ui->welcome->setVisible(false);
    if (active_ds == -1) {
        active_ds = ll;
        ui->begin->setVisible(false);
        ui->welcome->setText("Linked List selected...");
    } else {
        // ask before changing
    }
}


void MainWindow::on_stack_pbut_clicked()
{
    // ui->welcome->setVisible(false);
    if (active_ds == -1) {
        ui->begin->setVisible(false);
        ui->welcome->setText("Stack selected...");
    } else {
        // ask before changing
    }
}


void MainWindow::on_knowmore_clicked()
{
    // open the smol window
    if (active_ds == array) {
        ArrayKnowmore w;
        w.setModal(true);
        w.exec();
    }
}


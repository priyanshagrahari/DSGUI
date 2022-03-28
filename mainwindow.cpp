#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arrayknowmore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->knowmore->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_array_pbut_clicked()
{
    // ui->welcome->setVisible(false);
    ui->begin->setVisible(false);
    ui->welcome->setText("Array selected...");
    ui->knowmore->setVisible(true);
}


void MainWindow::on_ll_pbut_clicked()
{
    // ui->welcome->setVisible(false);
    ui->begin->setVisible(false);
    ui->welcome->setText("Linked List selected...");
}


void MainWindow::on_stack_pbut_clicked()
{
    // ui->welcome->setVisible(false);
    ui->begin->setVisible(false);
    ui->welcome->setText("Stack selected...");
}


void MainWindow::on_knowmore_clicked()
{
    // open the smol window
    ArrayKnowmore w;
    w.setModal(true);
    w.exec();
}


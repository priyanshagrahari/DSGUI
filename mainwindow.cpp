#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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


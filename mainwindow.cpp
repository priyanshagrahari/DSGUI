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


void MainWindow::on_clickme_clicked()
{
    if (ui->clickme->text() == "CLICK ME!") {
        ui->message->setText("you're gay xd");
        ui->clickme->setText("BYE :)");
    } else {
        exit(0);
    }
}


#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include <QDesktopServices>

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_pushButton_2_clicked()
{
    this->close();
}


void AboutWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/priyanshagrahari/DSGUI/"));
}


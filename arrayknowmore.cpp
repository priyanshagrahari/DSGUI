#include "arrayknowmore.h"
#include "ui_arrayknowmore.h"

ArrayKnowmore::ArrayKnowmore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArrayKnowmore)
{
    ui->setupUi(this);
    ui->textBrowser->setOpenExternalLinks(true);
}

ArrayKnowmore::~ArrayKnowmore()
{
    delete ui;
}

void ArrayKnowmore::on_pushButton_clicked()
{
    this->close();
}


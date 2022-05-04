#include "hashtablewindow.h"
#include "aboutwindow.h"
#include "qdialog.h"
#include "qdialogbuttonbox.h"
#include "qlabel.h"
#include "ui_hashtablewindow.h"

HashTableWindow::HashTableWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HashTableWindow)
{
    ui->setupUi(this);

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);
    connect(about, SIGNAL(clicked()), SLOT(about_clicked()));

    // ht exclusive
    ui->delp->setDisabled(true);
    ui->del->setDisabled(true);
    ui->ins->setDisabled(true);
    ui->insp->setDisabled(true);
    ui->sea->setDisabled(true);
    ui->seap->setDisabled(true);
    ui->set->setValue(7);

    int max_val = 1000000;
    ui->del->setMaximum(max_val);
    ui->ins->setMaximum(max_val);
    ui->sea->setMaximum(max_val);
}

HashTableWindow::~HashTableWindow()
{
    delete ui;
}

void HashTableWindow::on_ll_pbut_clicked()
{
    QDialog dlg(this);
    QVBoxLayout la(&dlg);
    QLabel ed;
    la.addWidget(&ed);
    ed.setText("This will take you to the start screen.\nThis hash table instance will be reset.");

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

void HashTableWindow::about_clicked() {
    AboutWindow aw(this);
    aw.setModal(true);
    aw.exec();
}


void HashTableWindow::on_setp_clicked()
{
    int v = ui->set->text().toInt();
    hash = v;
    for (int i = 0; i < v; i ++) {
        QTreeWidgetItem *n = new QTreeWidgetItem(ui->treeWidget);
        n->setText(0, QString::number(i));
        heads.push_back(n);
        ui->treeWidget->addTopLevelItem(n);
        values.push_back({});
    }
    ui->set->cleanText();
    ui->set->setDisabled(true);
    ui->setp->setDisabled(true);

    ui->delp->setDisabled(false);
    ui->del->setDisabled(false);
    ui->ins->setDisabled(false);
    ui->insp->setDisabled(false);
    ui->sea->setDisabled(false);
    ui->seap->setDisabled(false);
    return;
}


void HashTableWindow::on_insp_clicked()
{
    int v = ui->ins->text().toInt();
    int index = v % hash;
    values[index].push_back(v);
    QTreeWidgetItem *n = new QTreeWidgetItem(heads[index]);
    n->setText(1, QString::number(v));
    heads[index]->addChild(n);
    ui->treeWidget->clearSelection();
    heads[index]->setExpanded(true);
    n->setSelected(true);
    return;
}


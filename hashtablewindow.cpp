#include "hashtablewindow.h"
#include "aboutwindow.h"
#include "qdialog.h"
#include "qdialogbuttonbox.h"
#include "qlabel.h"
#include "ui_hashtablewindow.h"
#include <algorithm>

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
    children[index].push_back(n);
    ui->treeWidget->clearSelection();
    heads[index]->setExpanded(true);
    n->setSelected(true);
    ui->del->clear();
    return;
}


void HashTableWindow::on_seap_clicked()
{
    int v = ui->sea->text().toInt();
    int index = v % hash;
    if (std::find(values[index].begin(), values[index].end(), v) != values[index].end()) {
        ui->seas->setText(QString::number(v) + " found under index " + QString::number(index) + "!");
        ui->treeWidget->clearSelection();
        for (auto c : children[index]) {
            if (c->text(1) == QString::number(v)) {
                heads[index]->setExpanded(true);
                c->setSelected(true);
                ui->del->clear();
            }
        }
        return;
    }
    ui->seas->setText(QString::number(v) + " not found :(");
    return;
}


void HashTableWindow::on_delp_clicked()
{
    int v = ui->del->text().toInt();
    int index = v % hash;
    for (std::vector<QTreeWidgetItem*>::iterator i = children[index].begin(); i < children[index].end(); i ++) {
        if ((*i)->text(1) == QString::number(v)) {
            heads[index]->setExpanded(true);
            ui->dels->setText("Deleted " + QString::number(v) + " under index " + QString::number(index));
            QTreeWidgetItem *delete_me = (*i);
            children[index].erase(i);
            heads[index]->removeChild(delete_me);
            delete delete_me;
            values[index].erase(std::find(values[index].begin(), values[index].end(), v));
            ui->treeWidget->clearSelection();
            ui->del->clear();
            return;
        }
    }
    ui->dels->setText(QString::number(v) + " not found :(");
    return;
}


void HashTableWindow::on_treeWidget_itemSelectionChanged()
{
    ui->del->setValue(ui->treeWidget->currentItem()->text(1).toInt());
    return;
}


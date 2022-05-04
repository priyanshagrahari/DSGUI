#include "queuewindow.h"
#include "aboutwindow.h"
#include "qdialog.h"
#include "qdialogbuttonbox.h"
#include "ui_queuewindow.h"

QueueWindow::QueueWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QueueWindow)
{
    ui->setupUi(this);

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);
    connect(about, SIGNAL(clicked()), SLOT(about_clicked()));

    // queue exclusive
    q = new Queue();
    ui->lineEdit->setValidator(new QIntValidator(INT_MIN, INT_MAX, this));
}

QueueWindow::~QueueWindow()
{
    delete ui;
}

Queue::Queue() {
    front = nullptr;
    back = nullptr;
}

Queue::~Queue() {
    Node *t = front, *q;
    while (t != NULL) {
        q = t;
        t = t->get_n();
        delete q;
    }
}

Node *Queue::get_front() {
    return front;
}

Node *Queue::Enqueue(int v) {
    Node *n = new Node(v);
    if (back == nullptr) {
        front = n;
        back = n;
        return n;
    }
    back->set_n(n);
    back = n;
    return n;
}

int Queue::Dequeue() {
    if (front == nullptr) {
        return -1;
    }
    Node *p = front;
    int r = front->get_v();
    front = front->get_n();
    delete p;
    if (front == nullptr) {
        back = nullptr;
    }
    return r;
}

void QueueWindow::on_ll_pbut_clicked()
{
    QDialog dlg(this);
    QVBoxLayout la(&dlg);
    QLabel ed;
    la.addWidget(&ed);
    ed.setText("This will take you to the start screen.\nThis queue instance will be reset.");

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                       |QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), &dlg, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), &dlg, SLOT(reject()));

    la.addWidget(buttonBox);
    dlg.setLayout(&la);
    dlg.setModal(true);

    if(dlg.exec() == QDialog::Accepted)
    {
        this->hide();
        QWidget *parent = this->parentWidget();
        if (this->isMaximized()) {
            parent->showMaximized();
        } else {
            parent->show();
        }
    }
    dlg.close();
}

void QueueWindow::about_clicked() {
    AboutWindow aw(this);
    aw.setModal(true);
    aw.exec();
}

void QueueWindow::populate() {
    Node *t = q->get_front();
    ui->treeWidget->clear();
    while (t != nullptr) {
        QTreeWidgetItem *n = new QTreeWidgetItem(ui->treeWidget);
        n->setText(0, QString::number(t->get_v()));
        n->setText(1, QString::number((long long) t));
        ui->treeWidget->addTopLevelItem(n);
        t = t->get_n();
    }
    return;
}

void QueueWindow::on_pushButton_clicked()
{
    // enqueue clicked
    int val = ui->lineEdit->text().toInt();
    q->Enqueue(val);
    populate();
    return;
}


void QueueWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}


void QueueWindow::on_pushButton_2_clicked()
{
    // dequeue clicked
    if (q->get_front() == nullptr) {
        ui->label_3->setText("Queue is empty!");
        return;
    }
    int val = q->Dequeue();
    ui->label_3->setText(QString::number(val));
    populate();
    return;
}


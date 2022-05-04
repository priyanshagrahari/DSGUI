#include "stackwindow.h"
#include "aboutwindow.h"
#include "qdialog.h"
#include "qdialogbuttonbox.h"
#include "ui_stackwindow.h"

StackWindow::StackWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StackWindow)
{
    ui->setupUi(this);

    QSpacerItem *vsp = new QSpacerItem(10, 30);
    ui->buttonList->addItem(vsp);

    QPushButton *about = new QPushButton("About");
    ui->buttonList->addWidget(about);
    connect(about, SIGNAL(clicked()), SLOT(about_clicked()));

    // stack exclusive
    s = new Stack();
    ui->lineEdit->setValidator(new QIntValidator(INT_MIN, INT_MAX, this));
}

StackWindow::~StackWindow()
{
    delete ui;
}

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node *t = top;
    while (t != nullptr) {
        Node *q = t;
        t = t->get_n();
        delete q;
    }
}

Node *Stack::Push(int v) {
    Node *n = new Node(v);
    if (top == nullptr) {
        top = n;
        return n;
    }
    n->set_n(top);
    top = n;
    return n;
}

int Stack::Pop() {
    if (top == nullptr) return -1;
    int r = top->get_v();
    Node *dme = top;
    top = top->get_n();
    delete dme;
    return r;
}

Node *Stack::get_top() {
    return top;
}

void StackWindow::populate() {
    ui->treeWidget->clear();
    Node *t = s->get_top();
    while (t != nullptr) {
        QTreeWidgetItem *n = new QTreeWidgetItem(ui->treeWidget);
        n->setText(0, QString::number(t->get_v()));
        n->setText(1, QString::number((long long)t));
        ui->treeWidget->addTopLevelItem(n);
        t = t->get_n();
    }
    return;
}

void StackWindow::on_pushButton_clicked()
{
    // push clicked
    int val = ui->lineEdit->text().toInt();
    s->Push(val);
    populate();
    return;
}


void StackWindow::on_pushButton_2_clicked()
{
    // pop clicked
    if (s->get_top() != nullptr) {
        int val = s->Pop();
        ui->label_3->setText(QString::number(val));
        populate();
        return;
    }
    ui->label_3->setText("Stack empty!");
    return;
}


void StackWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
    return;
}

void StackWindow::on_ll_pbut_clicked()
{
    QDialog dlg(this);
    QVBoxLayout la(&dlg);
    QLabel ed;
    la.addWidget(&ed);
    ed.setText("This will take you to the start screen.\nThis stack instance will be reset.");

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

void StackWindow::about_clicked() {
    AboutWindow aw(this);
    aw.setModal(true);
    aw.exec();
}

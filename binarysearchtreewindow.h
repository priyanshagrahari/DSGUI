#ifndef BINARYSEARCHTREEWINDOW_H
#define BINARYSEARCHTREEWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>

namespace Ui {
class BinarySearchTreeWindow;
}

class BinarySearchTreeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BinarySearchTreeWindow(QWidget *parent = nullptr);
    ~BinarySearchTreeWindow();

private slots:
    void on_ll_pbut_clicked();

    void about_clicked();

    void on_inp_clicked();

    void on_dlp_clicked();

private:
    Ui::BinarySearchTreeWindow *ui;
    std::vector<int> bst_values;
    int tsize;
    std::map<QGraphicsEllipseItem*, std::vector<int>::iterator> el;
    QGraphicsScene *s;
    QPen *pen;
    QBrush *brush;
    void drawNode(int, int, std::vector<int>::iterator);
    void connectNodes(int,int, int,int);
    void drawTree();

    void bst_insert(int);
    void bst_delete(int);
    void move_up_l(int);
    void move_up_r(int);
};

#endif // BINARYSEARCHTREEWINDOW_H

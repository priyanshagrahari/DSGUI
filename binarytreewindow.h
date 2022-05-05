#ifndef BINARYTREEWINDOW_H
#define BINARYTREEWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>

namespace Ui {
class BinaryTreeWindow;
}

class BinaryTreeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BinaryTreeWindow(QWidget *parent = nullptr);
    ~BinaryTreeWindow();

private slots:
    void on_ll_pbut_clicked();

    void about_clicked();

    void on_inp_clicked();

private:
    Ui::BinaryTreeWindow *ui;
    std::vector<int> bt_values;
    QGraphicsScene *s;
    QPen *pen;
    QBrush *brush;
    void drawNode(int, int, int);
    void connectNodes(int,int, int,int);
    void drawTree();
};

#endif // BINARYTREEWINDOW_H

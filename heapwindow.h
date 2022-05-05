#ifndef HEAPWINDOW_H
#define HEAPWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>

namespace Ui {
class HeapWindow;
}

class HeapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HeapWindow(QWidget *parent = nullptr);
    ~HeapWindow();

private slots:
    void on_ll_pbut_clicked();

    void about_clicked();

    void on_inp_clicked();

    void on_dlp_clicked();

private:
    Ui::HeapWindow *ui;
    std::vector<int> h_values;
    QGraphicsScene *s;
    QPen *pen;
    QBrush *brush;
    void drawNode(int, int, std::vector<int>::iterator);
    void connectNodes(int,int, int,int);
    void drawTree();

    void heapify();
    void heapify_(int);
};

#endif // HEAPWINDOW_H

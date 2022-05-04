#ifndef ARRAYWINDOW_H
#define ARRAYWINDOW_H

#include <QMainWindow>

namespace Ui {
class ArrayWindow;
}

class ArrayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArrayWindow(QWidget *parent = nullptr);
    ~ArrayWindow();

private slots:
    void on_sizeset_clicked();

    void on_sizereset_clicked();

    void on_treeWidget_itemSelectionChanged();

    void on_newvalue_returnPressed();

    void on_index_returnPressed();

    void on_ll_pbut_clicked();

    void about_clicked();

private:
    Ui::ArrayWindow *ui;
    int *arr;
    int size;
};

#endif // ARRAYWINDOW_H

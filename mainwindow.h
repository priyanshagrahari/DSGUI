#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arraywindow.h"
#include "linkedlistwindow.h"
#include "stackwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_array_pbut_clicked();
    void on_ll_pbut_clicked();
    void on_stack_pbut_clicked();

    void q_clicked();
    //void

private:
    Ui::MainWindow *ui;

    int active_ds;
    enum ds {
        array,
        ll,
        stack,
        queue,
        btree,
        bstree,
        heap,
        htable
    } dstructs;
    ArrayWindow arr_win;
    LinkedListWindow ll_win;
    StackWindow stk_win;
};

#endif // MAINWINDOW_H

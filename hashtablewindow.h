#ifndef HASHTABLEWINDOW_H
#define HASHTABLEWINDOW_H

#include "qtreewidget.h"
#include <QMainWindow>

namespace Ui {
class HashTableWindow;
}

class HashTableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HashTableWindow(QWidget *parent = nullptr);
    ~HashTableWindow();

private slots:
    void on_ll_pbut_clicked();

    void about_clicked();

    void on_setp_clicked();

    void on_insp_clicked();

private:
    Ui::HashTableWindow *ui;

    int hash;

    std::vector<QTreeWidgetItem*> heads;
    std::vector<std::vector<int>> values;
};

#endif // HASHTABLEWINDOW_H

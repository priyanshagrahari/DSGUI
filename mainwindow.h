#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_knowmore_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef STACKWINDOW_H
#define STACKWINDOW_H

#include <QMainWindow>

namespace Ui {
class StackWindow;
}

class StackWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StackWindow(QWidget *parent = nullptr);
    ~StackWindow();

private:
    Ui::StackWindow *ui;
};

#endif // STACKWINDOW_H

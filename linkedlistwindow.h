#ifndef LINKEDLISTWINDOW_H
#define LINKEDLISTWINDOW_H

#include <QMainWindow>

namespace Ui {
class LinkedListWindow;
}

class LinkedListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LinkedListWindow(QWidget *parent = nullptr);
    ~LinkedListWindow();

private:
    Ui::LinkedListWindow *ui;
};

#endif // LINKEDLISTWINDOW_H

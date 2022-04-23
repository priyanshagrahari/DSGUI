#ifndef ARRAY_H
#define ARRAY_H

#include <QMainWindow>

namespace Ui {
class Array;
}

class Array : public QMainWindow
{
    Q_OBJECT

public:
    explicit Array(QWidget *parent = nullptr);
    ~Array();

private:
    Ui::Array *ui;
};

#endif // ARRAY_H

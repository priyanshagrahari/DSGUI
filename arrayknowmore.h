#ifndef ARRAYKNOWMORE_H
#define ARRAYKNOWMORE_H

#include <QDialog>

namespace Ui {
class ArrayKnowmore;
}

class ArrayKnowmore : public QDialog
{
    Q_OBJECT

public:
    explicit ArrayKnowmore(QWidget *parent = nullptr);
    ~ArrayKnowmore();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ArrayKnowmore *ui;
};

#endif // ARRAYKNOWMORE_H

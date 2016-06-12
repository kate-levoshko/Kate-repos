#ifndef BUYDIALOG_H
#define BUYDIALOG_H

#include <QDialog>
#include "product.h"

namespace Ui {
class BuyDialog;
}

class BuyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuyDialog(QWidget *parent = 0);
    ~BuyDialog();
    void init(Product* pr);
private slots:
    void on_cancelButton_clicked();

    void on_countSpinBox_valueChanged(int arg1);

    void on_buyButton_clicked();

private:
    Ui::BuyDialog *ui;
    Product* pr;
};

#endif // BUYDIALOG_H

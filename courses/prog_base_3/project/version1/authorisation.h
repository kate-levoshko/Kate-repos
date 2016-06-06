#ifndef AUTHORISATION_H
#define AUTHORISATION_H

#include <QDialog>

namespace Ui {
class authorisation;
}

class authorisation : public QDialog
{
    Q_OBJECT

public:
    explicit authorisation(QWidget *parent = 0);
    ~authorisation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::authorisation *ui;
};

#endif // AUTHORISATION_H

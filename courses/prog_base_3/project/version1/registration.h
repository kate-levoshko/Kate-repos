#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = 0);
    ~registration();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registration *ui;
};

#endif // REGISTRATION_H

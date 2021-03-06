#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();

private slots:
    void on_registerButton_clicked();
    bool Registration::isCorrectData();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H

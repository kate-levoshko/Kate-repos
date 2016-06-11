#ifndef PERSONALOFFICE_H
#define PERSONALOFFICE_H

#include <QWidget>

namespace Ui {
class PersonalOffice;
}

class PersonalOffice : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalOffice(QWidget *parent = 0);
    ~PersonalOffice();

private slots:
    void on_logOutButton_clicked();

    void on_backButton_clicked();

private:
    Ui::PersonalOffice *ui;
};

#endif // PERSONALOFFICE_H

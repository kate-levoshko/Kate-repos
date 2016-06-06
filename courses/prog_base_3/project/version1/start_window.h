#ifndef START_WINDOW_H
#define START_WINDOW_H

#include <QMainWindow>

namespace Ui {
class start_window;
}

class start_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit start_window(QWidget *parent = 0);
    ~start_window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::start_window *ui;
};

#endif // START_WINDOW_H

#ifndef BUCKETGUI_H
#define BUCKETGUI_H

#include <QWidget>

namespace Ui {
class BucketGUI;
}

class BucketGUI : public QWidget
{
    Q_OBJECT

public:
    explicit BucketGUI(QWidget *parent = 0);
    ~BucketGUI();

private:
    Ui::BucketGUI *ui;
};

#endif // BUCKETGUI_H

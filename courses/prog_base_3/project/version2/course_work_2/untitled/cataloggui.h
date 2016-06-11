#ifndef CATALOGGUI_H
#define CATALOGGUI_H

#include <QWidget>

namespace Ui {
class CatalogGUI;
}

class CatalogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogGUI(QWidget *parent = 0);
    ~CatalogGUI();

private slots:
    void on_personalOfficeButton_clicked();

private:
    Ui::CatalogGUI *ui;
};

#endif // CATALOGGUI_H

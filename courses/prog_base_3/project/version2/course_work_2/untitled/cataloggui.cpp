#include "cataloggui.h"
#include "ui_cataloggui.h"
#include "personaloffice.h"

CatalogGUI::CatalogGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CatalogGUI)
{
    ui->setupUi(this);
}

CatalogGUI::~CatalogGUI()
{
    delete ui;
}

void CatalogGUI::on_personalOfficeButton_clicked()
{
    PersonalOffice* w = new PersonalOffice();
    this->close();
    w->show();
}

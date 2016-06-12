#include "bucketgui.h"
#include "ui_bucketgui.h"

BucketGUI::BucketGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BucketGUI)
{
    ui->setupUi(this);
}

BucketGUI::~BucketGUI()
{
    delete ui;
}

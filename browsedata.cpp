#include "browsedata.h"
#include "ui_browsedata.h"

BrowseData::BrowseData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseData)
{
    ui->setupUi(this);
}

BrowseData::~BrowseData()
{
    delete ui;
}

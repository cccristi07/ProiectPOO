#ifndef BROWSEDATA_H
#define BROWSEDATA_H

#include <QDialog>

namespace Ui {
class BrowseData;
}

class BrowseData : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseData(QWidget *parent = 0);
    ~BrowseData();

private:
    Ui::BrowseData *ui;
};

#endif // BROWSEDATA_H

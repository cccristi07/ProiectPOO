#ifndef COMPARE_H
#define COMPARE_H

#include <QDialog>
#include "monod.h"
#include "moser.h"
#include "powel.h"
#include "dialog.h"
#include "oxigen.h"
namespace Ui {
class Compare;
}

class Compare : public QDialog
{
    Q_OBJECT

public:
    explicit Compare(QWidget *parent = 0);
    ~Compare();

    Ui::Compare *ui;
    void plotCompare(Monod*, Moser*, Powel*, Oxigen*);
};

#endif // COMPARE_H

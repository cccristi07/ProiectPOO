#ifndef TABEL_H
#define TABEL_H

#include <QDialog>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QVector>
#include <moser.h>
#include "monod.h"

namespace Ui {
class Tabel;
}

class Tabel : public QDialog
{
    Q_OBJECT

public:
    explicit Tabel(QWidget *parent = 0);
    ~Tabel();
    QSqlTableModel *model;

public:
    Ui::Tabel *ui;

    void dataShow(Monod *m);
private slots:
    //void on_tableView_activated(const QModelIndex &index);
    //void on_tableWidget_activated(const QModelIndex &index);

};

#endif // TABEL_H

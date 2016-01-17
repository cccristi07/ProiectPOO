#include "tabel.h"
#include "ui_tabel.h"
#include "QtGui"
#include "monod.h"
#include "moser.h"
#include "powel.h"
#include "oxigen.h"
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>


Tabel::Tabel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tabel)
{
    ui->setupUi(this);
}

Tabel::~Tabel()
{
    delete ui;
}

/*void Tabel::dataShow(QVector<double> t, QVector<double> DO, QVector<double> pH, QVector<double> S, QVector<double> O2)
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("Input Data");
    for(int i = 0; i< 17; i++)
    {
        model->insertRows(i, 5);
        model->setData(model->index(i, 0), t[i]);
        model->setData(model->index(i, 1), DO[i]);
        model->setData(model->index(i, 2), pH[i]);
        model->setData(model->index(i, 3), S[i]);
        model->setData(model->index(i, 4), O2[i]);

    }
    model->submitAll();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Timp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Densitate Optica"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("pH"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Substrat NNH2"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Oxigen dizolvat"));


    //model->setEditStrategy(QAbstractItemView::NoEditTriggers);

}*/



//void Tabel::dataShow(Monod *m)
//{

//    QSqlTableModel *model = new QSqlTableModel;
//    model->setTable("Input Data");
//    for(int i = 0; i< t.size(); i++)
//    {
//        model->insertRows(i, 5);
//        model->setData(model->index(i, 0), t[i]);
//        model->setData(model->index(i, 1), DO[i]);
//        model->setData(model->index(i, 2), pH[i]);
//        model->setData(model->index(i, 3), S[i]);
//        model->setData(model->index(i, 4), O2[i]);

//    }
//    model->submitAll();
//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Timp"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Densitate Optica"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("pH"));
//    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Substrat NNH2"));
//    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Oxigen dizolvat"));

//}



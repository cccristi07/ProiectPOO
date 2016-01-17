#ifndef OXIGEN_H
#define OXIGEN_H
#include "getdata.h"
#include <QString>
#include <QVector>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>


class Oxigen:
        public getData
{
private:
    double Ks;
    double Kc;
    double umax;
    QVector<double> x;
    QVector<double> y;
    QVector<double> U;
public:
    Oxigen(QString f) : getData(f) { calculate();  }
    Oxigen();
    void calculate();
    QVector<double> getX() const;
    QVector<double> getY() const;
    QVector<double> getS() const;
    QVector<double> getU() const;
    double getKs();
    double getKc();
    double getUMax();
    double getErr(int n);
};
#endif // OXIGEN_H

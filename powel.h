#ifndef POWEL_H
#define POWEL_H
#include <QString>
#include <QVector>
#include "getdata.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

class Powel:
        public getData
{
private:
    double Ks;
    double Ki;
    QVector<double> x;
    QVector<double> y;
    QVector<double> U;
public:
    Powel(QString f) : getData(f) { calculate();  }
    Powel();
    void calculate();
    QVector<double> getX() const;
    QVector<double> getY() const;
    QVector<double> getS() const;
    QVector<double> getU() const;
    double getKs();
    double getKi();
    double getErr(int n);
};

#endif // MOSER_H

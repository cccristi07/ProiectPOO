#ifndef POWELL_H
#define POWELL_H
#include <QString>
#include <QVector>
#include "getdata.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

class Powell:
        public getData
{
private:
    double umax;
    double Ks;
    double Kd;
    QVector<double> x;
    QVector<double> y;
    QVector<double> U;
public:
    Powell(QString f) : getData(f) { calculate();  }
    Powell();
    void calculate();
    QVector<double> getX() const;
    QVector<double> getY() const;
    QVector<double> getS() const;
    QVector<double> getU() const;
};

#endif // POWELL_H

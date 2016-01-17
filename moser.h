#ifndef MOSER_H
#define MOSER_H
#include <QString>
#include <QVector>
#include "getdata.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

class Moser:
        public getData
{
private:
    double umax;
    double Ks;
    QVector<double> x;
    QVector<double> y;
    QVector<double> U;
public:
    Moser(QString f) : getData(f) { calculate();  }
    Moser();
    void calculate();
    QVector<double> getX() const;
    QVector<double> getY() const;
    QVector<double> getS() const;
    QVector<double> getU() const;
    double getUMax();
    double getKs();
    double getErr(int n);
};

#endif // MOSER_H

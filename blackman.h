#ifndef BLACKMAN_H
#define BLACKMAN_H

#endif // BLACKMAN_H


#include <QString>
#include <QVector>
#include "getdata.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>



class blackman :
        public getData
{

private:
   double umax;
   double Ks;
   QVector<double> x;
   QVector<double> y;
   QVector<double> U;

public:
    blackman(QString f) : getData(f) { calculate();  }
    Monod();
    void calculate();
    QVector<double> getX() const;
    QVector<double> getY() const;
    QVector<double> getS() const;
    QVector<double> getU() const;

};
#endif // BLACKMAN_H

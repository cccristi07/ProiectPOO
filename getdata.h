#ifndef GETDATA_H
#define GETDATA_H
#include <fstream>
#include <QVector>
#include <vector>
#include <QString>


class getData
{
protected:
   int rows;
   QVector<double>   t;
   QVector<double>  DO;
   QVector<double>  pH;
   QVector<double>  S;
   QVector<double>  O2;

public:
    getData(); // default constructor
    getData(QString );
    int getExp();//for debug purposes
    int getRows(); // for debug purposes
    ~getData();
    QVector<double> getTime();
    QVector<double> get_DO();
    QVector<double> get_PH();
    QVector<double> get_S();
    QVector<double> get_O2();

};

#endif // GETDATA_H

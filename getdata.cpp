#include "getdata.h"
#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

getData::getData(QString file)
{


    QFile f(file);

    if(! f.open(QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QMessageBox err;
        err.setText("Fisierul cautat nu exista");
        err.exec();

    }
    else
    {

        QTextStream stream(&f);



        stream >> rows;
        t.resize(rows);
        DO.resize(rows);
        pH.resize(rows);
        S.resize(rows);
        O2.resize(rows);


        for(int i = 0 ; i<rows; i++)
        {

            stream >> t[i] >> DO[i] >> pH[i] >> S[i] >> O2[i];

        }
    }

}

getData::getData()
{


}



int getData::getRows()
{
    return rows;

}


getData::~getData()
{

}

QVector<double> getData::getTime()
{
    return t;
}

QVector<double> getData::get_DO()
{
    return DO;

}

QVector<double> getData::get_PH()
{
    return pH;
}

QVector<double> getData::get_S()
{
    return S;

}

QVector<double> getData::get_O2()
{
    return O2;
}

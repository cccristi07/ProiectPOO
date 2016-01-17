#include "moser.h"
#include "getdata.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <QDebug>
#include <qmath.h>
using namespace boost::numeric::ublas;

template<class T>
bool InvertMatrix(const matrix<T>& input, matrix<T>& inverse)
{
    typedef permutation_matrix<std::size_t> pmatrix;

    // create a working copy of the input
    matrix<T> A(input);

    // create a permutation matrix for the LU-factorization
    pmatrix pm(A.size1());

    // perform LU-factorization
    int res = lu_factorize(A, pm);
    if (res != 0)
        return false;

    // create identity matrix of "inverse"
    inverse.assign(identity_matrix<T> (A.size1()));

    // backsubstitute to get the inverse
    lu_substitute(A, pm, inverse);

    return true;
}


Moser::Moser()
{

}
void Moser::calculate()
{
    U.resize(rows);
    int n = 2;
    matrix<double> A(rows,2);
    matrix<double> b(rows,1);     // matrix equation is A*q = b ;
    matrix<double> q(2,1);
    matrix<double> aux(2,2);



    qSort(S);

    for(int i = 1 ; i< rows ; i ++ ){
        S[i] -= S[0];
        U[i] = (DO[i] - DO[i-1])/DO[i] ;
    }

    S[0] = 0 ;
    U[0] = 0 ;
    qSort(U);


    for(int i = 0 ; i < rows ; i ++ )
    {
//        if( DO[i] < 0  )
//        {
//            rows--;
//            A.resize(rows,4,true);
//            b.resize(rows,1,true);
//            continue;

//        }

       A.insert_element(i,0, U[i]);
       A.insert_element(i,1, -pow(S[i],n));
       b.insert_element(i,0,-U[i]*pow(S[i],n));
    }

    matrix<double> trans(2, rows);
    matrix<double> inv(2,2);
    matrix<double> ATA(2,2);
    matrix<double> pseudo(2,rows);

    // A' * A
    trans = boost::numeric::ublas::trans(A);
    ATA = boost::numeric::ublas::prod(trans, A);
    InvertMatrix<double>(ATA,inv);
    //boost::numeric::ublas::permutation_matrix<double> pm(A.size2());
    //inv.assign(identity_matrix<double> (A.size2()));
    //boost::numeric::ublas::lu_substitute(A, pm, inv);


    pseudo = boost::numeric::ublas::prod(inv, trans );
    q = boost::numeric::ublas::prod(pseudo , b);


    umax = fabs(q(1,0));
    umax*=3.6;
    Ks = fabs(q(0,0));
    x.resize(501);
    y.resize(501);

    for(int i = 0 ; i< 501 ; i++ )
    {
        x[i] = fabs(S[rows-1])*i/501.0;
        y[i] = umax*pow(x[i],n)/(Ks + pow(x[i],n));
    }

}
QVector<double> Moser::getX() const
{
    return x;
}

QVector<double> Moser::getY() const
{
    return y;
}

QVector<double> Moser::getS() const
{
    return S;
}

QVector<double> Moser::getU() const
{
    return U;
}
double Moser::getUMax()
{
    return umax;
}
double Moser::getKs()
{
    return Ks;
}

double Moser::getErr(int n )
{
    double err = 0;
    double norm = 0;


    for(int i = 0 ; i < S.size()-1 ; i++)
    {
        err += pow(fabs(U[i] - umax * pow(S[i],n)/(Ks + pow(S[i],2) )),n);
        norm += pow(fabs(U[i]) ,n);
    }

    return pow(err/rows,(double)1/n)/pow(norm/rows,(double)1/n);
}

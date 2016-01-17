#include "powel.h"
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

Powel::Powel()
{

}

void Powel::calculate()
{
    U.resize(rows);
    matrix<double> A(rows,3);
    matrix<double> b(rows,1);     // matrix equation is A*q = b ;
    matrix<double> q(3,1);
    matrix<double> aux(3,3);



    qSort(S);

    for(int i = 1 ; i< rows ; i ++ )
    {
        S[i] -= S[0];
        U[i] = (DO[i] - DO[i-1])/DO[i] ;
    }

    S[0] = S[1];
    U[0] = U[1] ;
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
       A.insert_element(i,1, U[i]*S[i]);
       A.insert_element(i,2, U[i]*S[i]*S[i]);
       b.insert_element(i,0,S[i]*(1-U[i]));
    }

    matrix<double> trans(3, rows);
    matrix<double> inv(3,3);
    matrix<double> ATA(3,3);
    matrix<double> pseudo(3,rows);

    // A' * A
    trans = boost::numeric::ublas::trans(A);
    ATA = boost::numeric::ublas::prod(trans, A);
    InvertMatrix<double>(ATA,inv);

    pseudo = boost::numeric::ublas::prod(inv, trans);
    q = boost::numeric::ublas::prod(pseudo , b);

    Ks = fabs(q(0,0));
    Ki = 1/fabs(q(2,0));
    Ki*=5;
    x.resize(501);
    y.resize(501);
   // std::cout << q;


    for(int i = 0 ; i< 501 ; i++ )
    {
        x[i] = fabs(S[rows-1])*i/501;
        y[i] = x[i]/((Ks + x[i])*(1+x[i]/Ki));

    }

}
QVector<double> Powel::getX() const
{
    return x;
}

QVector<double> Powel::getY() const
{
    return y;
}

QVector<double> Powel::getS() const
{
    return S;
}

QVector<double> Powel::getU() const
{
    return U;
}

double Powel::getKs()
{
    return Ks;
}

double Powel::getKi()
{
    return Ki;
}

double Powel::getErr(int n)
{
    double err = 0 ;
    double norm = 0 ;

    for(int i = 1 ; i < S.size()-1 ; i++)
    {
        err += pow(fabs(U[i] - S[i]/( (Ks + S[i] )*(1+S[i]/Ki))),n);
        norm += pow(fabs(U[i]) ,n );
    }

    return pow(err/rows,(double)1/n)/pow(norm/rows,(double)1/n);
}

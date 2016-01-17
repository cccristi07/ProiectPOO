#include "oxigen.h"
#include "getdata.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <QDebug>
#include <qmath.h>
#include <QVector>
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
Oxigen::Oxigen()
{

}

void Oxigen::calculate()
{
    U.resize(rows);
    matrix<double> A(rows,4);
    matrix<double> b(rows,1);     // matrix equation is A*q = b ;
    matrix<double> q(4,1);
    matrix<double> aux(4,4);

    QVector<double> c;


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

        if( DO[i] < 0  || O2[i] < 0 )
        {
            rows--;
            A.resize(rows,4,true);
            b.resize(rows,1,true);
            continue;

        }

       A.insert_element(i,0, U[i]);
       A.insert_element(i,1, O2[i]);
       A.insert_element(i,2, S[i]);
       A.insert_element(i,3, -S[i]*O2[i]);
       b.insert_element(i,0, -U[i]*O2[i]*S[i]);
    }



    matrix<double> trans(4, rows);
    matrix<double> inv(4,4);
    matrix<double> ATA(4,4);
    matrix<double> pseudo(4,rows);



    // A' * A
    trans = boost::numeric::ublas::trans(A);
    ATA = boost::numeric::ublas::prod(trans, A);
    InvertMatrix<double>(ATA,inv);

    pseudo = boost::numeric::ublas::prod(inv, trans);
    q = boost::numeric::ublas::prod(pseudo , b);


    Ks = fabs(q(1,0));
    Kc = fabs(q(2,0));
    umax = fabs(q(3,0));
    //umax/=1.5;
    x.resize(501);
    y.resize(501);
    c.resize(501);


    for(int i = 0 ; i< 501 ; i++ )
    {
        x[i] = fabs(S[rows-1])*i/501.0;
        c[i] = (double)fabs(O2[rows-1])*i/501;
        y[i] = (umax * x[i]*fabs(c[i]))/((Ks + x[i])* (Kc + fabs(c[i])));//eroare

    }

}

QVector<double> Oxigen::getX() const
{
    return x;
}

QVector<double> Oxigen::getY() const
{
    return y;
}

QVector<double> Oxigen::getS() const
{
    return S;
}

QVector<double> Oxigen::getU() const
{
    return U;
}

double Oxigen::getKs()
{
    return Ks;
}

double Oxigen::getKc()
{
    return Kc;
}

double Oxigen::getUMax()
{
    return umax;
}

double Oxigen::getErr(int n)
{


    double err = 0;
    double norm = 0;


    for(int i = 0 ; i < S.size()-1 ; i++)
    {
        err += pow(fabs(U[i] - umax * (S[i]/(Ks + S[i])) *(O2[i]/( Kc + O2[i] )) ),n);
        norm += pow(fabs(U[i]) ,n );
    }

    return pow(err/rows,(double)1/n)/pow(norm/rows,(double)1/n);
}



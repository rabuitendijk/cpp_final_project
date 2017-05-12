#pragma once
#include <iostream>
#include <cstring>
#include "mVector.h"
#include "mMatrix.h"
using namespace std;
#include "mMath.h"
#include <string>
#include <sstream>
#include <cmath>

//Windows tostring support
/*template < typename T >
string to_string( const T& n )
{
    ostringstream stm ;
    stm << n ;
    return stm.str() ;
}*/

template<typename T>
mVector<T> cg(const mMatrix<T> &A, const mVector<T> &b, mVector<T> &x, T tol, int maxiter)
{
        mVector <T> Ap;
        T rsnew;
        T alpha;

        mVector <T> r=b-A*x;
        mVector <T> p=r;
        T rsold = r*r;


        for(int i=0;i<maxiter;i++){
            Ap=A*p;
            if (p*Ap == 0) return x; //residual is 0

            alpha=(rsold)/(p*Ap);
            x = x + alpha * p;
            
            x.print();
            
            r = r - alpha * Ap;
            rsnew= (r*r);

            if (pow(rsnew,0.5)<tol){
                cout << "passed tolerance test." << endl;
                break;
            }
            if (rsold == 0) return x; //residual is 0
            p=r+(rsnew/rsold)*p;
            rsold=rsnew;

        }
    return x;
}

//Version 2
template<typename T>
mVector<T> cg_2(const mMatrix<T> &A, const mVector<T> &b, mVector<T> &x, T tol, int maxiter)
{
        mVector <T> r=b-A*x;
        mVector <T> rk;
        mVector <T> p=r;

        T alpha, rsnew, beta;
        for(int i=0;i<maxiter;i++){
            alpha = (r*r)/(p*p);
            x = x + alpha * p;
            
            x.print();
            rk = r;
            r = r - alpha*(A*p);
            rsnew= (r*r);

            if (pow(rsnew,0.5)<tol){
                cout << "passed tolerance test." << endl;
                break;
            }
            beta = (r*r)/(rk*rk);
            p=r+beta*p;

        }
    return x;
}


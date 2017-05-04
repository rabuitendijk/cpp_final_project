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
        cout<<(p).toString()<<endl;
        T rsold = r*r;

        int c = 0;

        for(int i=0;i<maxiter;i++){
            Ap=A*p;
            cout<<(A*p).toString()<<endl;
            if (p*Ap == 0) return x; //residual is 0

            alpha=(rsold)/(p*Ap);
            cout<<(p*Ap)<<endl;
            x = x + alpha * p;
            r = r - alpha * Ap;
            rsnew= (r*r);

            if (pow(rsnew,0.5)<tol){
                cout << "passed tolerance test." << endl;
                break;
            }
            if (rsold == 0) return x; //residual is 0
            p=r+(rsnew/rsold)*p;
            rsold=rsnew;

            c ++;
            if (c > 100){
                c = 1;
                cout<<i<<endl;
            }
        }
    return x;
}


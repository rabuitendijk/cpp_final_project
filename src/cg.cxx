#pragma once
#include <iostream>
#include <cstring>
#include "mVector.h"
#include "mMatrix.h"
using namespace std;

#include <string>
#include <sstream>


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

    //mVector <T> p_k=b-A*x;
    mVector <T> p_k=b;//FIXME

    mVector <T> r_k=p_k;
    mVector <T> x_k=x;

    mVector<T> p_k1;
    T beta_k;
    T alpha_k;
    mVector<T> x_k1;
    mVector<T> r_k1;

    T test;
    cout<<"ik ben net voor de loop"<<endl;
    for (int k = 0;k < maxiter; k++)
    {

         //alpha_k= (r_k*r_k)/(r_k * (A*p_k));
         test = (r_k * p_k);
         cout << to_string(test) << endl;

         alpha_k= (r_k*r_k)/(r_k * p_k);//FIXME
         cout<< k<<endl;
         x_k1=x_k+alpha_k*p_k;
         //r_k1=r_k-alpha_k*(A*p_k);
         r_k1=r_k-alpha_k*(p_k);//FIXME

         // tolerance
         if (r_k1.abs()< tol){
            return x_k1;
         }

         beta_k=(r_k1*r_k1)/(r_k*r_k);
         p_k1=r_k1+beta_k*p_k;

         // update new values
         p_k=p_k1;
         r_k=r_k1;
         x_k=x_k1;

    }


    return x_k1;
}


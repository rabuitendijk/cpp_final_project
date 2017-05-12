#include <iostream>
#include <cstring>

#include "mVector.h"
#include "mMatrix.h"
#include "Test.cpp"
#include "mMath.h"
#include "cg.cxx"

using namespace std;

int test1(){

    mVector<double> v(5);
    mVector<int> i = {1,2,3,4,5,6,7};
    mVector<int> i2 = {1,2,3,4,5,6,7};
    mVector<int> a = ((2*i)+i2);

	cout << i*i2 << endl;
	cout << v*i << endl;
	cout << i.abs() << endl;
	cout << i2.abs() << endl;
	mVector<double> v2 = {1,-2,3,-4,5};
	cout << v2.abs() << endl;

	v.print();
	i.print();
	i2.print();

    return 0;
}
int test2(){
mMatrix<double> A(6,6);
    A.insertList({1.0000 ,        0 ,        0 ,        0 ,        0,         0,
   25.0000,  -50.0000,   25.0000,         0,         0 ,        0,
         0,   25.0000,  -50.0000, 25.0000,         0 ,        0,
         0,         0,   25.0000 , -50.0000 ,  25.0000,         0,
         0 ,        0 ,        0,   25.0000,  -50.0000,   25.0000,
    0 ,        0 ,        0,         0,         0 ,   1.0000});

A.print();

mVector<double> b={1,2,3,4,5,6};
mVector<double> guess={1,1,1,1,1,1};

cout<< cg<double>(A,b,guess,0.0001,100).toString() << endl;




}

int main()
{
    //test1();
    //Test::run();
    test2();
    return 0;
}

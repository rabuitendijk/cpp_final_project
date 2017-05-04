//	Collection of autotests
//
#pragma once
#include <iostream>
#include "mVector.h"
#include "mMatrix.h"

using namespace std;

class Test
{
public:
        void run(){
            common_vector_tests();
        }
 private:   
        void common_vector_tests(){
	int  i = 0;
	int j=0;
	
	mVector<double> v = {1,2,3};
	mVector<double> v2(5);
	mVector<int> v3 = {1,2,3,4,5};
	mVector<double> v4 = v;
	mVector<double> v5(0);
	mVector<double> v6;

	if (!pass(i, j,  v.size()))
	    cout << "vector size error 1."  << endl;
	if (!pass(i, j,  v2.size()))
	    cout << "vector size error 2."  << endl;	
	if (!pass(i, j,  v3.size()))
	    cout << "vector size error 3."  << endl;
	if (!pass(i, j,  v4.size()))
	    cout << "vector size error 4."  << endl;		
	if (!pass(i, j,  v5.size()))
	    cout << "vector size error 5."  << endl;
	if (!pass(i, j,  v6.size()))
	    cout << "vector size error 6."  << endl;
	    
	if (i == j)
	    cout << "Size tests: ["<< i <<", " << j << "]";
            }
            
            
        bool pass(int& i, int &j, bool p){
	if (p)
	    i ++;
	j++;
	return p;
            }
            
};
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
        static void run(){
            vector_size();
            vector_equals_adding_subtraction();
             vector_scale();
        }
 private:   
        static void vector_size(){
	int  i = 0;
	int j=0;
	string desc = "Vector size";
	
	mVector<double> v = {1,2,3};
	mVector<double> v2(5);
	mVector<int> v3 = {1,2,3,4,5};
	mVector<double> v4 = v;
	mVector<double> v5(0);
	mVector<double> v6;

	pass(i, j, 	 v.size()	==	3, 	desc);
	pass(i, j,  	v2.size()	==	5,	desc);
	pass(i, j,  	v3.size()	==	5,	desc);
	pass(i, j,  	v4.size()	==	3,	desc);
	pass(i, j, 	 v5.size()	==	0,	desc);
	pass(i, j,  	v6.size()	==	0,	desc);
	    
	cout << desc << " tests passed: ["<< i <<" of " << j << "]" << endl;
	
	
            }
            
            static void vector_equals_adding_subtraction(){
	int  i = 0;
	int j=0;
	
	string desc = "Vector equals_adding_subtraction";
	
	mVector<double> v = {0,1,2};
	mVector<int> v5 = {0,1,2};
	mVector<int> v6 = {0,0,0};
	mVector<int> v7 = {0,-1,-2};
	mVector<double> v3 = {0,1,2};
	mVector<double> v4(3);
	mVector<double> v0 = {0,0,0};
	mVector<double> v2 = {0,-1,-2};
	

	pass(i,	 j, 	!(v	==	v5),	desc);
	pass(i, j,  	v	==	v3,	desc);
	pass(i, j,  	!(v	==	v0),	desc);
	pass(i, j,  	!(v	==	v2), 	desc);
	pass(i, j,  	(v-v3) ==	v0,	desc);
	pass(i, j,  	((v6-v5)	==	v7),	desc);
	pass(i, j,  	((v0-v3)	==	v2),	desc);
	
	cout <<  desc<<" tests passed: ["<< i <<" of " << j << "]" << endl;
	
	
            }
            
            static void vector_scale(){
	int  i = 0;
	int j=0;
	
	string desc = "Vector scale";
	mVector<int> vi1 = {1,2,3};
	int a = 0;
	int inv = -1;
	int a3 = 3;
	mVector<int> vi3 = {3,6,9};
	mVector<int> vi2 = {-1,-2,-3};
	mVector<int> vi = {0,0,0};
	mVector<int> v;
	double b = 0;
	mVector<double> vd1 = {1,2,3};
	mVector<double> vd = {0,0,0};
	
	pass(i,j,	(vi1*a == vi),	desc);
	pass(i,j,	(vi1*inv == vi2),	desc);
	pass(i,j,	(vi1*a3 == vi3),	desc);
	pass(i,j,	(vd1*b == vd),	desc);
	cout << desc << " tests passed: ["<< i <<" of " << j << "]" << endl;
	}
            
            
            
        static bool pass(int& i, int &j, bool p, string& desc){
	if (p)
	    i ++;
	j++;
	if (!p)
	    cout << desc << " " << j << endl;
	return p;
            }
            
};
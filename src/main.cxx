#include <iostream>
#include <cstring>

#include "mVector.h"
#include "mMatrix_SingularMap.h"

using namespace std;

int test1(){
    cout << "test lives" << endl;

    mVector<double> v(5);
    mVector<int> i = {1,2,3,4,5,6,7};
    mVector<int> i2 = {1,2,3,4,5,6,7};
    cout << v.toString() << endl;
    cout << i.toString() << endl;

    cout << "v == i: " << (v == i) << endl;
    cout << "i == i2: " << (i == i2) << endl;
    cout << (i+i2).toString() << endl;
    cout << (i-i2).toString() << endl;
    cout << (i+v).toString() << endl;
    cout << (i*-5).toString() << endl;
    cout << (5*i).toString() << endl;
    mVector<int> a = ((2*i)+i2);
    cout << a.toString() << endl;

	cout << i*i2 << endl;
	cout << v*i << endl;
    return 0;
}

/*
int test2(){
    cout << "test2 lives" << endl;

    mMatrix_SingularMap<double> v(5, 5);
	mMatrix_SingularMap<double> v0;
	
	for	(int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			v.set(i,j, (double)(i+.5*j));
		}
	}
	
	cout << v.toString() << endl;
	//cout << v.get(0,0) << endl;
	//cout << v.get(4,0) << endl;
	//cout << v.get(4,4)<< endl;
	//cout << v.get(0,4)<< endl;
	//v.set(0,7, 0);
	//cout << v.get(0,7)<< endl;
    return 0;
}


*/

int main()
{
    test1();

    return 0;
}

#include <iostream>
#include <cstring>
#include "mVector.h"
using namespace std;

int test(){
    cout << "test lives" << endl;

    mVector<double> v(5);
    mVector<int> i = {1,2,3,4,5,6,7};
    mVector<int> i2 = {1,2,3,4,5,6,7};
    cout << v.toString() << endl;
    cout << i.toString() << endl;

    cout << "v == i: " << (v == i) << endl;
    cout << "i == i2: " << (i == i2) << endl;
    cout << (i+i2).toString() << endl;
    cout << (i+v).toString() << endl;


    return 0;
}



int main()
{
    test();

    return 0;
}

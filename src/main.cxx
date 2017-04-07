#include <iostream>
#include <cstring>
#include "mVector.h"
using namespace std;

int test(){
    cout << "test lives" << endl;

    mVector<double> v(5);
    mVector<int> i = {1,2,3,4,5,6,7};
    cout << v.toString() << endl;
    cout << i.toString() << endl;

    return 0;
}



int main()
{
    test();

    return 0;
}

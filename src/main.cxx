#include <iostream>
#include <cstring>
#include "mVector.h"
using namespace std;

int test(){
    cout << "test lives" << endl;

    mVector v(5);
    cout << v.toString() << endl;

    return 0;
}

int main()
{
    test();

    return 0;
}

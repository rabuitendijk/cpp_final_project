#include "mMatrix.h"

int main()
{
 mMatrix<double> m(10,20);
 
//  m.insert(0,2,10);
//  m.insert(3,5,7);
//  m.insert(6,2,8);
 
 m[{0,0}] = 10;
 m[{0,5}] = 9;
 m[{0,5}] = 8;
 m[{5,5}] = 7;
 
 m.print();
 
 return 0;
}

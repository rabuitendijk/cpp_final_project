#include "mMath.h"

int main()
{
 unsigned int row = 2;
 unsigned int col = 3;
 
 mMatrix<double> m(row,col);
 mVector<double> v(col);
 
 for( unsigned int i=0; i<col; i++ )
 {
  v[i] = i;
  for( unsigned int j=0; j<row; j++ )
  {
   m[{j,i}] = i+j;
  }
 }

 mVector<double> u = m*v;
 
 v.print();
 u.print();
 
 std::cout << std::endl;
 
 m.print();
 
 mMatrix<double> n = Identity<double>(col);
 
 n = m;
 
 n.print();
 
 return 0;
}

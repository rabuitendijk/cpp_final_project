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
 
 m.print();

 v.print();
 u.print();
 
 std::cout << std::endl;
 mMatrix<double> n = Identity<double>(col);
 n.print();
 
 
 
 mMatrix<double> test_list(3,3);
 test_list.insertList( {1,2,3,4,5,6,7,8,9} );
 test_list.print();
 
 return 0;
}

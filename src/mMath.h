#pragma once

#include "mMatrix.h"
#include "mVector.h"

//matrix vector multiplication
template<typename T>
mVector<T> operator*( mMatrix<T> m , const mVector<T>& v )
{
 if( m.cols() != (unsigned int)v.size() )
 {
  std::cout << "matrix and vectors have different sizes and can not be multiplied" << std::endl;
  return mVector<T>( v.size() );
 }
 
 mVector<T> result( m.rows() );
 for( unsigned int i=0; i<m.rows(); i++ )
 {
  for( unsigned int j=0; j<m.cols(); j++ )
  {
   result[i] += v[j] * m[{i,j}];
  }
 }
 
 return result;
}

//Dot product
template<typename T, typename U>
U operator*(const mVector<T>& lh, const mVector<U>& rh){
    U ret = 0;
	if (lh.size() != rh.size())
	{
		cout << "Dot product: opletten, vectors niet de zelvde groote." << endl;
		return ret;
	}

    for(int i=0; i<lh.size(); i++){
		ret += rh[i]*lh[i];
	}

    return ret;
}

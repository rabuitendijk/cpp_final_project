#pragma once

#include "mMatrix.h"
#include "mVector.h"

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

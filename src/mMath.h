#pragma once

#include "mMatrix.h"
#include "mVector.h"

//matrix vector multiplication
template<typename T>
mVector<T> operator*( mMatrix<T> m , const mVector<T>& v )
{
 if( m.cols() != (unsigned int)v.size() )
 {
  std::cerr << "matrix and vectors have different sizes and can not be multiplied" << std::endl;
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

//matrix matrix multiplication
template<typename T>
mMatrix<T> operator*( mMatrix<T> m1 , mMatrix<T> m2 )
{
 if( m1.cols() != m2.rows() )
 {
  std::cerr << "cols of matrix1 are not equal to rows of matrix2" << std::endl;
  return mMatrix<T>( m1.rows(),m2.cols() );
 }
 
 mMatrix<T> result( m1.rows() , m2.cols() );
 for( unsigned int i=0; i<m1.cols(); i++ )
 {
  for( unsigned int j=0; j<m2.rows(); j++ )
   result[{j,i}] += m1[{i,j}]*m2[{i,j}];
 }
  
 return result;
}

//create indentity matrix
template<typename T>
mMatrix<T> Identity( const unsigned int& size )
{
 mMatrix<T> I( size , size );
 
 for( unsigned int i=0; i<size; i++ )
 {
  for( unsigned int j=0; j<size; j++ )
  {
   if( i == j )
    I[{j,i}] = 1;
  }
 }
 
 return I;
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


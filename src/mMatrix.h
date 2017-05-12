#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

template<typename T>
class mMatrix
{
private:
 const unsigned int n_rows;
 const unsigned int n_cols;

 std::map<unsigned int,T> map; //all data is stored in a map with the index and the value

 enum class Type
 {
  row,
  col
 }; 
 
 Type type;
 
 unsigned int getRow( const unsigned int& Index )
 {
  switch( this->type )
  {
   case Type::row :
    return Index/this->rows();
   break;
   case Type::col :
    return Index/this->cols();
   break;
  }
 }
 
 unsigned int getCol( const unsigned int& Index )
 {
  switch( this->type )
  {
   case Type::row :
    return Index - Index/this->rows()*this->cols();
   break;
   case Type::col :
    return Index - Index/this->cols()*this->rows();
   break;
  }
 }
 
 unsigned int getIndex( const unsigned int& row , const unsigned int& col )
 {
  switch( this->type )
  {
   case Type::row :
    return col*this->rows() + row;
   break;
   case Type::col :
    return row*this->cols() + col;
   break;
  }
 }
 
public: 
 mMatrix( const unsigned int& rows , const unsigned int& cols , const Type& type = Type::row ) : n_rows( rows ) , n_cols( cols ) , type( type ) {}  //default is row major, thus all rows will be set behind each other in a continuous data block

 unsigned int cols() const { return this->n_cols; }
 unsigned int rows() const { return this->n_rows; }
 
 unsigned int size() const
 {
  return this->n_rows*this->n_cols;
 }
 
 typename std::map<unsigned int,T>::iterator getBegin()
 { return this->map.begin(); }
 
 typename std::map<unsigned int,T>::iterator getEnd()
 { return this->map.end(); }
 
//  mMatrix<T>& operator=( mMatrix<T> m )
//  {
//   this->map = std::map<unsigned int,T>();
//   
//   typename std::map<unsigned int,T>::iterator it;
//   
//   for( it = m.getBegin(); it != m.getEnd(); it++ )
//    this->map[it->first] = it->second;
//   
//   return *this;
//  }
 
 void insert( const unsigned int& row , const unsigned int& col , const T& value )
 {
  if( row > this->rows() || col > this->cols() )
  {
   std::cout << "the value to be added is out of bound, matrix is " << this->rows() << "x" << this->cols() << " but value is (" << row << "," << col << ")" << std::endl;
   return;
  }

  this->map.insert( std::pair<unsigned int,T>( getIndex( row , col ) , value ) );
  
//   switch( this->type )
//   {
//    case Type::row : 
//     this->map.insert( std::pair<unsigned int,T>( col*this->rows()+row , value ) );
//    break;
//    case Type::col :
//     this->map.insert( std::pair<unsigned int,T>( row*this->cols()+col , value ) );  
//    break;
//   }

  return;
 }

 T& operator[] ( const std::array<unsigned int,2>& array )
 {
  if( array[0] >= this->rows() || array[1] >= this->cols() )
  {
   std::cout << "the value to be added is out of bound, matrix is " << this->n_rows << "x" << this->n_cols << " but value is (" << array[0] << "," << array[1] << ")" << std::endl;
  }

  unsigned int index;
  
  index = getIndex( array[0] , array[1] );
  
//   switch( this->type )
//   { 
//    case Type::row :
//     index = array[1]*this->rows()+array[0];
//    break;
//    case Type::col :
//     index = array[0]*this->cols()+array[1];
//    break;
//   }

  if( map.find( index ) == map.end() )
   map[index] = 0;
  
  return this->map[index];
 }
 
 void insertList( std::initializer_list<T> list )
 {
  if( list.size() != this->size() )
  {
   std::cerr << "list size and matrix size are not equal" << std::endl;
   return;
  }
  
  typename std::initializer_list<T>::iterator it;
  unsigned int counter = 0;
  for( it=list.begin(); it!=list.end(); it++ )
  {
   this->insert( getRow(counter) , getCol(counter) , *it );
   counter++;
  }
  
//   return *this;
 }

 std::string toString()
 {
  std::ostringstream string;
  typename std::map<unsigned int,T>::iterator it;
  
  for( std::size_t i=0; i<this->rows(); i++ )
  {
   for( std::size_t j=0; j<this->cols(); j++ )
   {
    it = this->map.find( getIndex(i,j) );
    
    if( it != this->map.end() )
     string << it->second << " ";
    else
     string << "0 ";
    
//     switch( this->type )
//     {
//      case Type::row :
//       it = this->map.find( j*this->rows()+i );
//       if( it != this->map.end() )
//        string << it->second << " ";
//       else
//        string << "0 ";
//      break;
//      case Type::col :
//       it = this->map.find( j+this->cols()*i );
//       if( it != this->map.end() )
//        string << it->second << " ";
//       else
//        string << "0 ";
//      break;
//     }
   }
   string << "\n";
  }

  return string.str();
 }

 void print()
 {
  std::cout << this->toString() << std::endl;

  return;
 }

};

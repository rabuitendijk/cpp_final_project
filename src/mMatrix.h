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
 
 unsigned int IndexToRow( const unsigned int& Index )
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
 
 unsigned int IndexToCol( const unsigned int& Index )
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
 
 unsigned int RowColToIndex( const unsigned int& row , const unsigned int& col )
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
 
 void insert( const unsigned int& row , const unsigned int& col , const T& value )
 {
  if( row > this->rows() || col > this->cols() )
  {
   std::cout << "the value to be added is out of bound, matrix is " << this->rows() << "x" << this->cols() << " but value is (" << row << "," << col << ")" << std::endl;
   return;
  }

  this->map.insert( std::pair<unsigned int,T>( RowColToIndex( row , col ) , value ) );

  return;
 }

 T& operator[] ( const std::array<unsigned int,2>& array )
 {
  if( array[0] >= this->rows() || array[1] >= this->cols() )
  {
   std::cout << "the value to be added is out of bound, matrix is " << this->n_rows << "x" << this->n_cols << " but value is (" << array[0] << "," << array[1] << ")" << std::endl;
  }

  unsigned int index;
  
  index = RowColToIndex( array[0] , array[1] );

  if( map.find( index ) == map.end() )
   map[index] = 0;
  
  return this->map[index];
 }
 
 mMatrix<T>& insertList( std::initializer_list<T> list )
 {
  if( list.size() != this->size() )
  {
   std::cerr << "list size and matrix size are not equal" << std::endl;
   return *this;
  }
  
  typename std::initializer_list<T>::iterator it;
  unsigned int counter = 0;
  for( it=list.begin(); it!=list.end(); it++ )
  {
   this->insert( IndexToRow(counter) , IndexToCol(counter) , *it );
   counter++;
  }
  
  return *this;
 }

 std::string toString()
 {
  std::ostringstream string;
  typename std::map<unsigned int,T>::iterator it;
  
  for( std::size_t i=0; i<this->rows(); i++ )
  {
   for( std::size_t j=0; j<this->cols(); j++ )
   {
    it = this->map.find( RowColToIndex(i,j) );
    
    if( it != this->map.end() )
     string << it->second << " ";
    else
     string << "0 ";
    
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

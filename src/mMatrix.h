#include <vector>
#include <map>
#include <sstream>
#include <iostream>

template<typename T>
class mMatrix
{
private:
 const unsigned int rows;
 const unsigned int cols;
 
 std::map<unsigned int,T> map; //all data is stored in a map with the index and the value
 
 enum class Type
 {
  row,
  col
 } type;
 
public: 
 mMatrix( const unsigned int& rows , const unsigned int& cols , const Type& type = Type::row ) : rows( rows ) , cols( cols ) , type( type ) {}  //default is row major, thus all rows will be set behind each other in a continuous data block

 unsigned int size() const
 {
  return this->rows*this->cols;
 }
 
//  void insert( const unsigned int& row , const unsigned int& col , const T& value )
//  {
//   if( row > this->rows || col > this->cols )
//   {
//    std::cout << "the value to be added is out of bound, matrix is " << this->rows << "x" << this->cols << " but value is (" << row << "," << col << ")" << std::endl;
//    return;
//   }
//   
//   switch( this->type )
//   {
//    case Type::row : 
//     this->map.insert( std::pair<unsigned int,T>( row*this->rows+col , value ) );
//    break;
//    case Type::col :
//     this->map.insert( std::pair<unsigned int,T>( col*this->cols+row , value ) );  
//    break;
//   }
//   
//   return;
//  }
 
 T& operator[] ( const std::array<unsigned int,2>& array )
 {
  if( array[0] > this->rows || array[1] > this->cols )
  {
   std::cout << "the value to be added is out of bound, matrix is " << this->rows << "x" << this->cols << " but value is (" << array[0] << "," << array[1] << ")" << std::endl;
  }
  
  unsigned int index;
  switch( this->type )
  {
   case Type::row : 
    index = array[0]*this->rows+array[1];
   break;
   case Type::col :
    index = array[1]*this->cols+array[0]; 
   break;
  }
  
  return this->map[index]; 
 }
 
 std::string toString()
 {
  std::ostringstream string;
  typename std::map<unsigned int,T>::iterator it;
  
  for( std::size_t i=0; i<this->cols; i++ )
  {
   for( std::size_t j=0; j<this->rows; j++ )
   {
    switch( this->type )
    {
     case Type::row : 
      it = this->map.find( i*this->rows+j );
      if( it != this->map.end() )
       string << it->second << " ";
      else
       string << "0 ";
     break;
     case Type::col :
      it = this->map.find( i+this->cols*j );
      if( it != this->map.end() )
       string << it->second << " ";
      else
       string << "0 ";
     break;
    }
   }
   string << std::endl;
  }
  
  return string.str();
 }

 void print()
 {
  std::cout << this->toString() << std::endl;
   
  return;
 }

};

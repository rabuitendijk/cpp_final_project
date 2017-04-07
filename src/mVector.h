#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#include <string>
#include <sstream>


//Windows tostring support
template < typename T >
string to_string( const T& n )
{
    ostringstream stm ;
    stm << n ;
    return stm.str() ;
}



class mVector{

    public:
        mVector() : length(0){};
        mVector(int length) : length(length){};

        string toString(){
            return "mVector[length: "+to_string(length)+",]";
        }
    private:
        int length;

};

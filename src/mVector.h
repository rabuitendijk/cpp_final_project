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


template<typename T>
class mVector{

    public:
        mVector() : length(0){};
        mVector(int length) : length(length), data(new T[length]){};



        mVector(initializer_list<T> list) : mVector((int)list.size()) {
                typename initializer_list<T>::iterator it;

                int i = 0;
                for (it = list.begin();it != list.end(); it++)
                {

                    data[i++] = *it;
                }

        }
        ~mVector(){length = 0; delete [] data;};

        string toString(){
            string temp = "mVector[length: "+to_string(length)+", <";
            for(int i=0; i<length-1; i++){
                temp += to_string(data[i])+", ";
            } temp += to_string(data[length-1]);

            return temp+">]";
        }
    private:
        int length;
        T* data;

};

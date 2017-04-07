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
        //CONSTRUCTORS AND DESTRUCTORS
            //Default constructor
            mVector() : length(0){};

            //Empty constructor
            mVector(int length) : length(length), data(new T[length]){};


            //initializer_list contructor
            mVector(initializer_list<T> list) : mVector((int)list.size()) {
                    typename initializer_list<T>::iterator it;

                    int i = 0;
                    for (it = list.begin();it != list.end(); it++)
                    {

                        data[i++] = *it;
                    }

            }

            //Copy constructor
            mVector(const mVector & other) : mVector(other.size()){
                for(int i=0; i<length; i++)
                {
                    data[i] = other.get(i);
                }
            }

            //Destructor
            ~mVector(){length = 0; delete [] data;};

        //OPERATORS
            //If vectors do not contain the same datatype return false
            template<typename U>
            bool operator ==(const mVector<U> & other) const{
                return false;
            }

            //Check if contend is the same
            bool operator ==(const mVector<T> & other) const{
                if (length != other.size())
                    return false;

                for (int i=0; i<length; i++){
                    if (data[i] != other.get(i))
                    return false;
                }

                return true;
            }

            template<typename U>
            mVector<U> operator+ (const mVector<U> & other) const {
                if (length != other.size()){    //Size missmatch
                    mVector<U> ret(0);
                    return ret;
                }

                mVector<U> ret(other);
                for(int i=0; i<length; i++){
                    ret.set(i, ret.get(i)+data[i]);
                }


                return ret;
            }



        //FUNCTIONS
            int size() const{
                return length;
            }

            T get(int index) const {
                return data[index];
            }

            void set(int index, T value){
                data[index] = value;
            }

            //Prints a string reprensentation of this object
            string toString() const{
                if (length == 0)
                    return "mVector[length: 0]";
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

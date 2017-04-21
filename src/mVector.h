#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
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
                    data[i] = other[i];
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
                    if (data[i] != other[i])
                    return false;
                }

                return true;
            }

            //Add
            template<typename U>
            mVector<U> operator+ (const mVector<U> & other) const {
                if (length != other.size()){    //Size missmatch
                    mVector<U> ret(0);
                    return ret;
                }

                mVector<U> ret(other);
                for(int i=0; i<length; i++){
                    ret[i] += data[i];
                }


                return ret;
            }

            //Subtract
            template<typename U>
            mVector<U> operator- (const mVector<U> & other) const {
                if (length != other.size()){    //Size missmatch
                    mVector<U> ret(0);
                    return ret;
                }

                mVector<U> ret(other);
                for(int i=0; i<length; i++){
                    ret[i] -=data[i];
                }


                return ret;
            }

            mVector& operator= (const mVector<T> & other){
                length = other.size();
                data = new T[length];

                for (int i=0; i<length; i++)
                {
                    data[i] = other[i];
                }

                return *this;
            }


        //FUNCTIONS
            int size() const{
                return length;
            }

            T& operator[] (const int index) const{
                return data[index];
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
			
			T abs(){
				T ret;
				for(int i=0; i<length; i++)
				{
					ret += std::abs(data[i]);
				}
				return ret;
			}


    private:
        int length;
        T* data;

};

//Multiply vector with scalar
template<typename T, typename U>
mVector<T> operator*(const mVector<T>& lh, const U& rh){
    mVector<T> ret(lh);

    for (int i=0; i<lh.size(); i++)
    {
        ret[i] *= rh;
    }

    return ret;
}

//Multiply scaler with vector
template<typename T, typename U>
mVector<T> operator*(const U& lh, const mVector<T>& rh){
    mVector<T> ret(rh);

    for (int i=0; i<rh.size(); i++)
    {
        ret[i] *=  lh;
    }

    return ret;
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
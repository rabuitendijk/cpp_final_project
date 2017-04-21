/*
	Matrix claass implemented with the proffesors method.
*/
#pragma once
#include <map>
#include <sstream>
#include <iostream>
#include<string>
using namespace std;

template<typename T>
class mMatrix_SingularMap{
	
public:
		//Constructors
			mMatrix_SingularMap() : data(), width(0), height(0){};
			mMatrix_SingularMap(int w, int h): data(), width(w), height(h){};
		
			
		//Functions
		T get(const int i, const int j) const{
			if (i < 0 || i>= width || j<0 || j>= height)
			{
				cout << "Attempt to acces to index out of bounds given ["+to_string(i)+", "+to_string(j)+"] of"+toString() << endl;
				return;
			}
			
			array<int, 2> a = {i,j};
			return data[a];
		}
		
		void set(const int i, const int j, const T value){
			if (i < 0 || i>= width || j<0 || j>= height)
			{
				cout << "Attempt to wirte to index out of bounds given ["+to_string(i)+", "+to_string(j)+"] of"+toString() << endl;
				return;
			}
			
			array<int, 2> a = {i,j};
			data[a] =  value;
		}
		
		int getHeight() const{
			return height;
		}
		
		int getWidth() const{
			return width;
		}
		
		string toString() const{
			return "mMatrix["+to_string(width)+"," +to_string(height)+"]<TODO>";
		}
private:
	
	map<array<int, 2>, T> data;
	int height;
	int width;
};
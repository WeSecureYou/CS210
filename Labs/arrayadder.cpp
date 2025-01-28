//filename: arrayaddder.cpp
//Modify this program to overload subtraction operator and insertion operator
#include <iostream>
using namespace std;

#define MAXARRAY 5

class myarray 
{
private:
	int value[MAXARRAY];

public:
	void setvalue(int index, int newvalue){
		value[index]=newvalue;}
	int getvalue(int index){
		return value[index];}

	//member function
	/*
	myarray operator-(myarray array2)
	{
		myarray temparray;
		for (int i=0; i<MAXARRAY; i++)
			temparray.value[i]=value[i] - array2.value[i];
		return temparray;
	}
	*/
	//non-member function
	friend myarray operator-(myarray array1, myarray array2) {
		myarray temparray;
		for (int i = 0; i < MAXARRAY; i++)
			temparray.value[i] = array1.value[i] - array2.value[i];
		return temparray;
	};

};
	//insertion operator overloading 
	ostream& operator<<(ostream& os, myarray array) {
		os << "newarray: ";
		for (int i = 0; i < MAXARRAY; i++)
			os << array.getvalue(i) << " ";
		os << endl;
		return os;
	};

int main ()
{

	myarray array1, array2, array3;
	int i;
	
	//INITIALIZE 
	for (i=0; i<MAXARRAY; i++)
	{
		array1.setvalue(i,i);
		array2.setvalue(i,i+3);
	}
	
	//SUBTRACT
	array3=array1 - array2; 
	
	//PRINT 
	cout << array1 << array2 << array3;

	return 0;
}

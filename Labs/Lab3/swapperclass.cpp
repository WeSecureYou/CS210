#include <iostream>
#include "./swapperclass.h" 
using namespace std;

template <typename Ttype>
my_class<Ttype>::my_class(Ttype a, Ttype b)
{
	x = a;
	y = b;
}

template <typename Ttype>
void my_class<Ttype>::swapper()
{
	Ttype TempVal = x;
	x = y;
	y = TempVal;
} 

template <typename Ttype>
void my_class<Ttype>::printem(){	
	cout << "First value is: " << x << " Second value is: " << y << endl;
}

template my_class <int>;
template my_class <double>;
template my_class <char>;






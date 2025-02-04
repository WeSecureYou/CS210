#include <iostream>
#include "./swapperclass.h" 
using namespace std;

int main()
{
	my_class<int> tempInt(3, 48);
	tempInt.printem();
	tempInt.swapper();
	cout << "AFTER SWAP" << endl;
	tempInt.printem();
	cout << endl;

	my_class<double> tempDouble(5.5, 8.5);
	tempDouble.printem();
	tempDouble.swapper();
	cout << "AFTER SWAP" << endl;
	tempDouble.printem();
	cout << endl;

	my_class<char> tempChar('a', 'b');
	tempChar.printem();
	tempChar.swapper();
	cout << "AFTER SWAP" << endl;
	tempChar.printem();
}




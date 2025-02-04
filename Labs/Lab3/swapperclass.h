#pragma once
#include <iostream>
using namespace std;

template <typename Ttype>
class my_class
{
	Ttype x;
	Ttype y;
public:
	my_class(Ttype a, Ttype b);
	void swapper();
	void printem();
};
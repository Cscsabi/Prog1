#include "../../std_lib_facilities.h"

int recursive_fac(int n)
{
	return n>1 ? n*recursive_fac(n-1) : 1;
}

int iterative_fac(int n)
{
	int value = n;
	while (n-1 != 1)
	{
		value *= n-1;
		n -= 1;
	}

	return value;
}

int main()
{
	cout << "Recursievly" << endl << recursive_fac(15) << endl << recursive_fac(10) << endl;
	cout << "Iteratively" << endl << iterative_fac(15) << endl << iterative_fac(10) << endl;
}
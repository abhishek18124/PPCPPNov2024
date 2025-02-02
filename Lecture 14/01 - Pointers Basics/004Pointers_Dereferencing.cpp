#include<iostream>

using namespace std;

int main() {

	int x = 516;
	int *xptr = &x;

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	cout << "*xptr = " << *xptr << endl << endl;

	char ch = 'A';
	char* chptr = &ch;
	cout << ch << endl;
	cout << *chptr << endl << endl;

	double y = 3.14;
	double* yptr = &y;
	cout << y << endl;
	cout << *yptr << endl;

	return 0;
}
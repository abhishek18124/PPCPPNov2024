#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr = &x;

	cout << xptr << endl;

	xptr = xptr + 3;

	cout << xptr << endl;

	return 0;
}
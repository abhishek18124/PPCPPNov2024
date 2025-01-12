#include<iostream>

using namespace std;

void incr(int& ref) { // pass by ref
	ref++;
}

int main() {

	int a = 100;

	incr(a);

	cout << a << endl;

	return 0;
}
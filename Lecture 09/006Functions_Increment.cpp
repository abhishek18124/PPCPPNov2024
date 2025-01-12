#include<iostream>

using namespace std;

void incr(int a) {
	a++;
	cout << "inside incr after ++ a = " << a << endl;
}

int main() {

	int a = 10;

	incr(a);

	cout << "inside main after incr() a = " << a << endl;

	return 0;
}
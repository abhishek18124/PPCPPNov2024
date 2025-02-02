#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << " " << (void*)greet << endl;
	cout << (void*)&add << " " << (void*)add << endl;
	cout << (void*)&ascending << " " << (void*)ascending << endl;

	void(*gptr)() = &greet;
	int (*aptr)(int, int) = &add;
	bool (*ascptr)(int, int) = &ascending;

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl;

	greet();
	(*greet)();
	(*gptr)();
	gptr();

	cout << add(5, 10) << endl;
	cout << (*add)(5, 10) << endl;
	cout << (*aptr)(5, 10) << endl;
	cout << aptr(5, 10) << endl;

	cout << ascending(2, 6) << endl;
	cout << (*ascending)(2, 6) << endl;
	cout << (*ascptr)(2, 6) << endl;
	cout << ascptr(2, 6) << endl;

	return 0;
}
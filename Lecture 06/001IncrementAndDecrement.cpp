#include<iostream>

using namespace std;

int main() {

	int x = 10;

	x++; // or ++x

	cout << "x : " << x << endl;

	int y = 20;

	y--; // or --y

	cout << "y : " << y << endl;

	int a = 10;
	cout << a++ << endl;
	cout << a << endl;

	int b = 15;
	cout << ++b << endl;
	cout << b << endl;

	int c = 20;
	int d = ++c;
	cout << c << " " << d << endl;


	int e = 40;
	int f = e++;
	cout << e << " " << f << endl;


	return 0;
}
#include<iostream>

using namespace std;

int main() {

	char ch1; // declr.
	cin >> ch1;

	cout << "ch1 = " << ch1 << endl;

	char ch2;
	ch2 = 'B'; // assign.
	cout << "ch2 = " << ch2 << endl;

	char ch3 = 'C'; // initialisation
	cout << "ch3 = " << ch3 << endl;

	char ch4 = 'a';
	cout << (int)ch4 << endl;

	char ch5 = 'C';
	cout << (int)ch5 << endl;

	int x = 'd';
	cout << x << endl;

	char ch6 = '7';
	cout << (int)ch6 << endl;

	char ch7 = '8';
	cout << (int)ch7 << endl;
	cout << ch7 - '0' << endl;

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 4;

	int mask = 1 << k;

	cout << (n | mask) << endl;

	n = 42; // 101010
	k = 3;

	mask = 1 << k;

	cout << (n | mask) << endl;

	return 0;
}
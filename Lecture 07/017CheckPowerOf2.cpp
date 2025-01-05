#include<iostream>

using namespace std;

int main() {

	int n = 20;

	(n & (n - 1))  == 0 ? cout << "power of 2" << endl : cout << "not a power of 2" << endl;

	return 0;
}
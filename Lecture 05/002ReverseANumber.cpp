#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int rev = 0; // to store the reverse of 'n'

	while (n > 0) {
		int r = n % 10;
		rev = rev * 10 + r;
		n = n / 10;
	}

	cout << rev << endl;

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int s = 0; // to track the sum of digits of 'n'

	while (n > 0) {
		int r = n % 10;
		s = s + r;
		n = n / 10;
	}

	cout << s << endl;

	return 0;
}
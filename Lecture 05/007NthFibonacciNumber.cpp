#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {

		cout << n << endl;

	} else {

		// n >= 2

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		int i = 2;

		// int c;

		// while (i <= n) {
		// 	c = a + b;
		// 	a = b;
		// 	b = c;
		// 	i = i + 1;
		// }

		// cout << c << endl;

		while (i <= n) { // n-1 times // time : O(n)
			int c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}

		cout << b << endl;
	}


	return 0;
}
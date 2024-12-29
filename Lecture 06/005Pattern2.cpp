#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// iterate over the n rows from 1 to n

	int i = 1;

	while (i <= n) {

		// for the ith row, print i nos. starting from 1 in the inc. order

		int j = 1;
		while (j <= i) {
			cout << j << " ";
			j++;
		}

		cout << endl;

		i++;

	}

	return 0;
}
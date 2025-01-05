#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 15;
	int cnt = 0; // to track the no. of set bits in 'n'

	for (int k = 0; k <= 31; k++) {

		// check if the kth bit of n is set

		if ((n >> k) & 1) {
			// kth bit of n is set
			cnt++;
		}

	}

	cout << cnt << endl;

	return 0;
}
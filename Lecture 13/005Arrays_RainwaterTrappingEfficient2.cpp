// constraints 1 <= n <= 2e4

#include<iostream>

using namespace std;

const int maxN = 2e4;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : 3n.const ~ O(n)
	// space: n due to r[] ~ O(n)

	int r[maxN]; // based on constraints
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	int li = h[0];

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building

		li = max(li, h[i]);
		int wi = min(li, r[i]) - h[i];
		total += wi;

	}

	cout << total << endl;

	return 0;
}
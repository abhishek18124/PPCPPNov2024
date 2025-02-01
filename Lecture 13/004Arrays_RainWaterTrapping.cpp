#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : O(n^2)
	// space: O(1)

	int total = 0;

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building

		int li = h[i];// max(h[0...i])
		for (int j = i - 1; j >= 0; j--) {
			li = max(li, h[j]);
		}

		int ri = h[i]; // max(h[i...n-1])
		for (int j = i + 1; j < n; j++) {
			ri = max(ri, h[j]);
		}

		int wi = min(li, ri) - h[i];
		total += wi;

	}

	cout << total << endl;

	return 0;
}
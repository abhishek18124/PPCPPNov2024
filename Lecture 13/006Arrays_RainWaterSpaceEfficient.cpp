#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : O(n)
	// space: O(1)

	int i = 0;
	int j = n - 1;

	int l = h[0]; // mx(0 to i)
	int r = h[n - 1]; // mx(j to n-1)

	int total = 0;

	while (i <= j) {

		l = max(l, h[i]);
		r = max(r, h[j]);

		if (l < r) {

			// find out the water trapped on top of the ith building

			int wi = l - h[i];
			total += wi;
			i++;

		} else {

			// find out the water trapped on top of the jth building

			int wj = r - h[j];
			total += wj;
			j--;

		}

	}

	cout << total << endl;

	return 0;
}
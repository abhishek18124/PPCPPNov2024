#include<iostream>
#include<algorithm>

using namespace std;

// time : O(n^2)

int mostWater(int height[], int n) {

	int maxSoFar = 0;

	for (int i = 0; i <= n - 2; i++) {

		for (int j = i + 1; j <= n - 1; j++) {

			// find out the area of the container formed using the ith and jth line

			int w = j - i;
			int h = min(height[i], height[j]);
			int a = w * h;

			maxSoFar = max(maxSoFar, a);

		}

	}

	return maxSoFar;

}

// time : O(n)

int mostWaterOptimised(int height[], int n) {

	int maxSoFar = 0;

	int i = 0;
	int j = n - 1;

	while (i < j) {

		// find out the area of the container formed using the ith and jth line

		int w = j - i;
		int h = min(height[i], height[j]);
		int a = w * h;

		maxSoFar = max(maxSoFar, a);

		if (height[i] < height[j]) {
			i++;
		} else {
			j--;
		}

	}

	return maxSoFar;

}

int main() {

	int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(height) / sizeof(int);

	cout << mostWater(height, n) << endl;

	cout << mostWaterOptimised(height, n) << endl;

	return 0;
}
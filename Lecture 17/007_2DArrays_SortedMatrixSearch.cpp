#include<iostream>
#include<algorithm>

using namespace std;

// time : O(mlogn)

bool isPresent(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {

		// apply binary search to search for 't' in the ith row

		// if (binary_search(mat[i], mat[i + 1], t)) { // this will fail when n < max. colns
		// 	// 't' found in the ith row
		// 	return true;
		// }

		if (binary_search(mat[i], mat[i] + n, t)) {
			// 't' found in the ith row
			return true;
		}

	}

	// 't' is not found in the mat[][]

	return false;

}

int main() {

	int mat[][3] = {
		{40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 50;

	isPresent(mat, m, n, t) ? cout << t << " found" << endl :
	                               cout << t << " not found" << endl;


	return 0;
}
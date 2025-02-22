#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool cmp(int a, int b) {

	if (a > b) {
		// you want a should come before b
		return true;
	}

	return false;

}

int main() {

	// 1. creating a vector using initialiser list

	vector<int> v = {1, 0, 2, 4, 3};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 2. sorting a vector in the decreasing order

	// sort(v.begin(), v.end(), greater<int>());
	// sort(v.rbegin(), v.rend());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
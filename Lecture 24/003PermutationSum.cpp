#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, const vector<int>& c, vector<int>& perm) {

	// base case

	if (t == 0) { // you've built a valid permutation
		for (int x : perm) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	for (int op : c) { // t = 7, {2, 3, 5, 7}
		if (op <= t) {
			perm.push_back(op);
			generatePermutations(t - op, c, perm);
			perm.pop_back(); // backtracking
		}
	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm);

	return 0;
}
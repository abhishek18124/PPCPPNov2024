#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> f1(int A[], int n) {

	vector<int> ans;
	stack<int> s; // <index>

	for (int i = n - 1; i >= 0; i--) {

		// find the index of the nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any nearest smaller element to its right
			ans.push_back(n);
		} else {
			// whatever is at the top of the stack is the index of nearest smaller element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

vector<int> f2(int A[], int n) {

	vector<int> ans;
	stack<int> s; // <index>

	for (int i = 0; i <= n - 1; i++) {

		// find the index of the nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any nearest smaller element to its left
			ans.push_back(-1);
		} else {
			// whatever is at the top of the stack is the index of nearest smaller element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	return ans;

}

int main() {

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	// time : O(n)
	// space: O(n) due stk in f1() and f2()

	vector<int> nsr = f1(h, n); // linear
	vector<int> nsl = f2(h, n); // linear

	int maxSofar = 0;

	for (int i = 0; i < n; i++) { // linear

		int bestWidth = nsr[i] - nsl[i] - 1;
		int bestArea = h[i] * bestWidth;
		maxSofar = max(maxSofar, bestArea);

	}

	cout << maxSofar << endl;

	return 0;
}
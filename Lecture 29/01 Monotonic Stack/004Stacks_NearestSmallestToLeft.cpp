#include<iostream>
#include<stack>
#include<vector>

using namespace std;

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

	int A[] = {0, 3, 5, 4, 1, 6, 2};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f2(A, n);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
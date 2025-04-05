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

int main() {

	int A[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f1(A, n);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
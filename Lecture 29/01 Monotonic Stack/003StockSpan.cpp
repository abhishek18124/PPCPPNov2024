#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> stockSpan(int A[], int n) {

	vector<int> ans; // to store span
	stack<pair<int, int>> s; // <value, index>

	for (int i = 0; i < n; i++) {

		// find the idx of the nearest greater element to the left of A[i]

		while (!s.empty() and s.top().first <= A[i]) {
			s.pop();
		}

		int j; // to store the index of the nearest greater element to the left of A[i]

		if (s.empty()) {
			// there is no nearest greater element to the left of A[i]
			j = -1;
		} else {
			// whatever is at the top of the stack is the nearest greater element to the left A[i]
			j = s.top().second;
		}

		ans.push_back(i - j);

		s.push({A[i], i}); // s.push(make_pair(A[i], i));

	}

	return ans;

}

vector<int> stockSpan2(int A[], int n) {

	vector<int> ans; // to store span
	stack<int> s; // <index> // from index we can extract value for cmp

	for (int i = 0; i < n; i++) {

		// find the idx of the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j; // to store the index of the nearest greater element to the left of A[i]

		if (s.empty()) {
			// there is no nearest greater element to the left of A[i]
			j = -1;
		} else {
			// whatever is at the top of the stack is the nearest greater element to the left A[i]
			j = s.top();
		}

		ans.push_back(i - j);

		s.push(i);

	}

	return ans;

}

int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = stockSpan2(A, n);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
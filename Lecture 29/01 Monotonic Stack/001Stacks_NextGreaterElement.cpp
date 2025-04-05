#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

// time : O(n)
// space: O(n) due to stack

// [HW] try to solve this questions in linear
// time using monotonic stack but you have to
// scan the array left to right i.e. from 0 to n-1

//[HW] leetcode :  next greater node
//[HW] leetcode : next greater element IV

vector<int> f1(int A[], int n) {

	vector<int> ans;
	stack<int> s;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any nearest greater element to its right
			ans.push_back(-1);
		} else {
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f1(A, n);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
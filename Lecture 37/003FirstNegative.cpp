#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int arr[] = { -2, 0, -1, 2, -3, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	// time : O(n)
	// space: O(k) since queue tracks all negatives of a window
	// and in the worst case all elements in the window can be
	// negative

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window

	queue<int>  q; // to store negative numbers in a window
	vector<int> ans; // to store first negative number for each k-sized window

	// find the first negative number in the 1st window

	while (j < k) {
		if (arr[j] < 0) q.push(arr[j]);
		j++;
	}

	q.empty() ? ans.push_back(0) : ans.push_back(q.front());

	// find the first negative number in the remaining windows

	while (j < n) {

		// slide the window
		if (arr[i] < 0) q.pop();
		i++;
		if (arr[j] < 0) q.push(arr[j]);

		q.empty() ? ans.push_back(0) : ans.push_back(q.front());

		j++;

	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}


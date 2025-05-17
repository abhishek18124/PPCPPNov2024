/*

Given an array of non-negative integers of size n, find the maximum possible XOR between
any two numbers present in the array.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output: 28
	Explaination: The maximum result is 5 ^ 25 = 28

	Input: x[] = {1, 2, 3, 4, 5, 6, 7}
	Output: 7
	Explaination: The maximum result is 1 ^ 6 = 7

*/

#include<iostream>
#include<climits>

using namespace std;

class node {
public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right = NULL;
	}
};

class trie {

	node* root;

public:

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if (!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if (!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	// helper() will tell the maximum possible XOR involving n
	// in just single XOR operation with the help of trie

	int helper(int n) {
		int ans = 0; // to store the maximum possible XOR involing n
		node* cur = root;
		for (int i = 31; i >= 0; i--) {
			if ((n >> i) & 1) {
				// ith bit of n is set
				if (cur->left != NULL) {
					// ith bit of ans can also be set
					ans += (1 << i);
					cur = cur->left;
				} else {
					// ith bit of ans cannot be set
					cur = cur->right;
				}
			} else {
				// ith bit of n is not set
				if (cur->right != NULL) {
					// ith bit of ans can be set
					ans += (1 << i);
					cur = cur->right;
				} else {
					// ith bit of ans cannot be set
					cur = cur->left;
				}
			}
		}

		cout << n << "^" << (ans ^ n) << " = " << ans << endl;

		return ans;
	}

	// time : n.32 ~ O(n)
	// space:

	int maximumPairXOR(int x[], int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) {
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}
};

int main() {

	int x[] = {2, 4, 5, 8, 10};
	int n = sizeof(x) / sizeof(int);

	// // time : O(n^2)

	// int maxSoFar = 0;

	// for (int i = 0; i <= n - 2; i++) {
	// 	for (int j = i + 1; j <= n - 1; j++) {
	// 		cout << x[i] << "^" << x[j] << " = " << (x[i]^x[j]) << endl;
	// 		maxSoFar = max(maxSoFar, x[i] ^ x[j]);
	// 	}
	// 	cout << endl;
	// }

	// cout << maxSoFar << endl;

	trie t;

	for (int i = 0; i < n; i++) {
		t.insert(x[i]);
	}

	cout << t.maximumPairXOR(x, n) << endl;

	return 0;
}
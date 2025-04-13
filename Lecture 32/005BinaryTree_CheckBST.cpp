/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int findMinimum(TreeNode* root) {
	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}
	return root->val;
}


int findMaximum(TreeNode* root) {
	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}
	return root->val;
}

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) { // empty tree is a bst
		return true;
	}

	// recursive case

	// 1. ask your friend to check if the leftSubtree is a bst

	bool leftIsBst = checkBST(root->left);

	// 2. ask your friend to check if the rightSubtree is a bst

	bool rightIsBst = checkBST(root->right);

	// 3. check if the bst property works at the root node

	bool rootIsBst = root->val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and rootIsBst;

}

class triple {
public:
	bool isBst;
	int minVal;
	int maxVal;
};

// time : O(n)

triple checkBSTEfficient(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.isBst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	triple left = checkBSTEfficient(root->left);
	triple right = checkBSTEfficient(root->right);
	bool rootIsBst = root->val > left.maxVal and root->val < right.minVal ? true : false;

	t.isBst = left.isBst and right.isBst and rootIsBst;
	t.minVal = min(left.minVal, min(right.minVal, root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, root->val));

	return t;

}

bool checkBSTUsingRange(TreeNode* root, long long lb, long long ub) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	return root->val > lb and root->val < ub and
	       checkBSTUsingRange(root->left, lb, root->val) and
	       checkBSTUsingRange(root->right, root->val, ub);

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "true" << endl : cout << "false" << endl;

	triple t = checkBSTEfficient(root);

	t.isBst ? cout << "true" << endl : cout << "false" << endl;

	long long lb = (long long)INT_MIN - 1;
	long long ub = (long long)INT_MAX + 1;

	checkBSTUsingRange(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}
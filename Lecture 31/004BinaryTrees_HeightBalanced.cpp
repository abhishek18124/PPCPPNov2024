
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>

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


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int computeHeight(TreeNode* root) {

	// base case

	if (!root) { // root == NULL
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. recursively, compute the height of the leftSubtree
	int x = computeHeight(root->left);

	// 2. recursively, compute the height of the rightSubtree
	int y = computeHeight(root->right);

	return 1 + max(x, y);

}

// time : O(n^2)

bool dfs(TreeNode* root) {

	// base case

	if (root == NULL) { // empty tree is HB, no HB prop. is violated
		return true;
	}

	// recursive case

	// check if the given tree is height-balanced or not

	// 1. ask your friend to check if the leftSubtree is heightBalanced

	bool leftIsBal = dfs(root->left);

	// 2. ask your friend to check if the rightSubtree is heightBalanced

	bool rightIsBal = dfs(root->right);

	// 3. check if the heightBalance prop. works at the root node

	bool rootIsBal = abs(computeHeight(root->left) - computeHeight(root->right)) <= 1 ? true : false;

	return leftIsBal and rightIsBal and rootIsBal;

}

class Pair {
public:
	int hgt;
	bool isBal;
};

// time : O(n)

Pair dfsEfficient(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		p.isBal = true;
		p.hgt = -1;
		return p;
	}

	// recursive case

	Pair left = dfsEfficient(root->left);
	Pair right = dfsEfficient(root->right);

	bool rootIsBal = abs(left.hgt - right.hgt) <= 1 ? true : false;

	p.hgt = 1 + max(left.hgt, right.hgt);
	p.isBal = left.isBal and right.isBal and rootIsBal;

	return p;

}

int main() {

	TreeNode* root = buildTree();

	dfs(root) ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	Pair p = dfsEfficient(root);

	p.isBal ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	return 0;
}
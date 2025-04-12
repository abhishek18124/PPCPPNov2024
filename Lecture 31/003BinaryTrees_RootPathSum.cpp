#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

int dfs(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	int cnt = 0; // to track no. of paths in the given tree
	// that start at root and whose sum is equal to targetSum

	// 1. ask your friend to cnt no. of paths in the leftSubtree
	// that start at root and whose sum is equal to targetSum-root->val

	cnt += dfs(root->left, targetSum - root->val);

	// 2. ask your friend to cnt no. of paths in the rightSubtree
	// that start at root and whose sum is equal to targetSum-root->val

	cnt += dfs(root->right, targetSum - root->val);

	if (root->val == targetSum) cnt++;

	return cnt;

}


int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(2);

	// root->left = new TreeNode(7);
	// root->left->left = new TreeNode(3);
	// root->left->left->left = new TreeNode(1);
	// root->left->left->right = new TreeNode(8);
	// root->left->right = new TreeNode(3);

	// root->right = new TreeNode(6);
	// root->right->left = new TreeNode(4);
	// root->right->right = new TreeNode(5);

	root = new TreeNode(4);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(8);
	root->left->right = new TreeNode(3);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	int targetSum = 4;

	cout << dfs(root, targetSum) << endl;

	return 0;
}
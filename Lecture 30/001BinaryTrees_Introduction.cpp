#include<iostream>

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

void printPreOrder(TreeNode* root) {

	// base case

	if (root == NULL) {
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. process the root node

	cout << root->val << " ";

	// 2. ask your friend to print the preOrder of leftSubtree

	printPreOrder(root->left);

	// 3. ask your friend to print the preOrder of rightSubtree

	printPreOrder(root->right);

}

void printInOrder(TreeNode* root) {

	// base case

	if (root == NULL) {
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. ask your friend to print the inOrder of leftSubtree

	printInOrder(root->left);

	// 2. process the root node

	cout << root->val << " ";

	// 3. ask your friend to print the inOrder of rightSubtree

	printInOrder(root->right);

}

int main() {

	TreeNode* root = NULL; // init, tree is empty

	root = new TreeNode(10);
	root->left = new TreeNode(20);
	root->right = new TreeNode(30);
	root->left->left = new TreeNode(40);
	root->left->right = new TreeNode(50);
	root->right->right = new TreeNode(60);
	root->left->right->left = new TreeNode(70);

	printPreOrder(root);
	cout << endl;


	printInOrder(root);
	cout << endl;

	return 0;
}
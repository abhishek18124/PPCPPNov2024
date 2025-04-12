/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {

		// base case

		if (root == NULL) {
			return false;
		}

		if (root->left == NULL and root->right == NULL) {
			if (root->val == targetSum) {
				// you've found a valid path from root-to-leaf whose sum is equal
				// to targetSum
				return true;
			}
			return false;
		}

		// recursive case

		// check if there is a root-to-leaf in the given tree
		// whose sum is equal to targetSum

		// 1. ask your friend to check if there is root-to-leaf in the
		// leftSubtree whose sum is equal to targetSum - root->val

		// 2. ask your friend to check if there is root-to-leaf in the
		// rightSubtree whose sum is equal to targetSum - root->val

		return hasPathSum(root->left,  targetSum - root->val) or
		       hasPathSum(root->right, targetSum - root->val);

	}
};
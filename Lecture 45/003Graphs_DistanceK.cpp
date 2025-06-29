/**
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // 1. convert the binary tree into a undirected graph

        map<TreeNode*, vector<TreeNode*>> adj;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* front = q.front(); q.pop();
            if (front->left != NULL) {
                adj[front].push_back(front->left);
                adj[front->left].push_back(front);
                q.push(front->left);
            }
            if (front->right != NULL) {
                adj[front].push_back(front->right);
                adj[front->right].push_back(front);
                q.push(front->right);
            }

        }

        // 2. with target as source, apply BFS to solve SSSP

        q.push(target); // target is the src

        map<TreeNode*, int> dis;
        dis[target] = 0;

        set<TreeNode*> vis;
        vis.insert(target);

        while (!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            for (TreeNode* ngb : adj[cur]) {
                if (vis.find(ngb) == vis.end()) {
                    vis.insert(ngb);
                    q.push(ngb);
                    dis[ngb] = dis[cur] + 1;
                }
            }

        }

        vector<int> ans;

        for (auto [node, d] : dis) {
            if (d == k) {
                ans.push_back(node->val);
            }
        }

        return ans;

    }
};
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

    void dfs(TreeNode* root, int sum, vector<int> &ans){
        if(!root) return;
        sum=10*sum+root->val;
        if(!root->left && !root->right) ans.push_back(sum);
        dfs(root->left, sum, ans);
        dfs(root->right, sum, ans);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
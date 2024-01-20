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
    void dfs(TreeNode* root,vector<int> &ans,int sum){
        if(!root){
            return ;
        }
        sum=sum*10+root->val;
        if(!root->left && !root->right){
            ans.push_back(sum);
        }
        dfs(root->left,ans,sum);
        dfs(root->right,ans,sum);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,0);
        return accumulate(ans.begin(),ans.end(),0);
    }
};
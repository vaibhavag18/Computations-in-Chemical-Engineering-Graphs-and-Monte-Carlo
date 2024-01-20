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
    void f(TreeNode* &root,int cursum,int &ans){
        if(!root)return;

        cursum=cursum*10+root->val;
        if(!root->left && !root->right){
            ans+=cursum;
            return;
        }

        if(root->left)f(root->left,cursum,ans);
        if(root->right)f(root->right,cursum,ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        f(root,0,ans);
        return ans;
    }
};